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

    return 0;
}
