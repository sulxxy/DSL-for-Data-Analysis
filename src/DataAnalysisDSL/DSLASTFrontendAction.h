//
// Created by zhiwei on 7/1/18.
//

#ifndef LLVM_DSLASTFRONTENDACTION_H
#define LLVM_DSLASTFRONTENDACTION_H

#include <clang/Frontend/FrontendAction.h>
#include "DSLASTFrontendAction.h"
#include "DSLASTConsumer.h"

class DSLASTFrontendAction : public clang::ASTFrontendAction {
public:
    DSLASTFrontendAction ();

    DSLASTFrontendAction (int a);

    virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
            clang::CompilerInstance &Compiler, llvm::StringRef InFile);
};

#endif //LLVM_DSLASTFRONTENDACTION_H
