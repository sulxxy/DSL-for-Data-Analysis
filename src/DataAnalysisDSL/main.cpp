//
// Created by zhiwei on 7/1/18.
//

#include <clang/Tooling/Tooling.h>
#include "DSLASTFrontendAction.h"

int main(int argc, char **argv) {
    //todo: sql table description
    llvm::outs() << "file: " << argv[1] << "\n";
    if (argc > 1) {
        clang::tooling::runToolOnCode(new DSLASTFrontendAction(4), argv[1]);
    }
}
