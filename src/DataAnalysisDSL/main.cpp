//
// Created by zhiwei on 7/1/18.
//

#include <clang/Tooling/Tooling.h>
#include <vector>
#include "DSLASTFrontendAction.h"
#include "DataSource.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 1) {
        llvm::outs() << "ERROR: Please specify input code" << "\n";
        return 0;
    }
    llvm::outs() << "file: " << argv[1] << "\n";

    DataSource *dataSource = new DataSource;
    if(!dataSource->buildConnection()){
        llvm::outs() << "ERROR: Could not connect to DB." << "\n";
        return 0;
    }

    vector<Variable> descriptions = dataSource->getDescription();
    DSLASTFrontendAction *DSLAction = new DSLASTFrontendAction(4, descriptions);
    clang::tooling::runToolOnCode(DSLAction, argv[1]);

    return 0;
}
