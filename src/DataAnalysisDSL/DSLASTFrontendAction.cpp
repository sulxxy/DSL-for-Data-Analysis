//
// Created by zhiwei on 7/1/18.
//

#include "clang/Frontend/CompilerInstance.h"
#include "DSLASTFrontendAction.h"

DSLASTFrontendAction::DSLASTFrontendAction ():clang::ASTFrontendAction(){}

DSLASTFrontendAction::DSLASTFrontendAction (int a):clang::ASTFrontendAction(){
    //todo: add sql table
}

std::unique_ptr<clang::ASTConsumer> DSLASTFrontendAction::CreateASTConsumer(
        clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::unique_ptr<clang::ASTConsumer>(new DSLASTConsumer(&Compiler.getASTContext()));
}
