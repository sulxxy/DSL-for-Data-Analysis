//
// Created by zhiwei on 7/1/18.
//

#include "DSLASTConsumer.h"

DSLASTConsumer::DSLASTConsumer(ASTContext *Context)
        : Visitor(Context) {}

void DSLASTConsumer::HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
}


