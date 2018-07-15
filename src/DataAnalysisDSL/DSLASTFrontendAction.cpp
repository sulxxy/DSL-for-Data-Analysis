//
// Created by zhiwei on 7/1/18.
//

#include "clang/Frontend/CompilerInstance.h"
#include "DSLASTFrontendAction.h"
#include "Variable.h"
#include "DataSource.h"

/*
DSLASTFrontendAction::DSLASTFrontendAction ():clang::ASTFrontendAction(){}

DSLASTFrontendAction::DSLASTFrontendAction(DataSource *dataSource):clang::ASTFrontendAction(){
    this->dataSource = dataSource;

}
 */

std::unique_ptr<clang::ASTConsumer> DSLASTFrontendAction::CreateASTConsumer(
        clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::unique_ptr<clang::ASTConsumer>(new DSLASTConsumer(&Compiler.getASTContext()/*todo: back, dataSource*/));
}
