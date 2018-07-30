//
// Created by zhiwei on 7/1/18.
//

#include <clang/Tooling/Tooling.h>
#include <vector>
#include "DSLASTFrontendAction.h"
#include "DataSource.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

int main(int argc, char **argv) {
    if (argc <= 1) {
        llvm::outs() << "ERROR: Please specify input code" << "\n";
        return 0;
    }
    llvm::outs() << "file: " << argv[1] << "\n";

    /*
    DataSource *dataSource = new DataSource;
    if(!dataSource->buildConnection()){
        llvm::outs() << "ERROR: Could not connect to DB." << "\n";
        return 0;
    }

    vector<Variable> descriptions = dataSource->getDescription();
    DSLASTFrontendAction *DSLAction = new DSLASTFrontendAction();
     */
    clang::tooling::runToolOnCode(new DSLASTFrontendAction, argv[1]);
    /*
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return 0;
     */

    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();               // Between StartObject()/EndObject(),
    writer.Key("hello");                // output a key,
    writer.String("world");             // follow by a value.
    writer.Key("testobj");
    writer.StartObject();
    writer.Key("objkey");
    writer.String("objstr");
    writer.EndObject();
    writer.Key("t");
    writer.Bool(true);
    writer.Key("f");
    writer.Bool(false);
    writer.Key("n");
    writer.Null();
    writer.Key("i");
    writer.Uint(123);
    writer.Key("pi");
    writer.Double(3.1416);
    writer.Key("a");
    writer.StartArray();                // Between StartArray()/EndArray(),
    for (unsigned i = 0; i < 4; i++)
        writer.Uint(i);                 // all values are elements of the array.
    writer.EndArray();
    writer.EndObject();

    // {"hello":"world","t":true,"f":false,"n":null,"i":123,"pi":3.1416,"a":[0,1,2,3]}
    cout << s.GetString() << endl;

    return 0;
}
