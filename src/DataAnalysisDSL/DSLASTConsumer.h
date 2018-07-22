//
// Created by zhiwei on 7/1/18.
//

#ifndef LLVM_DSLASTCONSUMER_H
#define LLVM_DSLASTCONSUMER_H


#include "DSLASTVisitor.h"
#include "clang/AST/ASTConsumer.h"

class DSLASTConsumer : public clang::ASTConsumer {
public:
    explicit DSLASTConsumer(ASTContext *Context);
    explicit DSLASTConsumer(ASTContext *Context, DataSource *dataSource);

    virtual void HandleTranslationUnit(clang::ASTContext &Context) ;

private:
    DSLASTVisitor Visitor;
    DataSource *dataSource;
    Comprehensions *comprehensions;

};


#endif //LLVM_DSLASTCONSUMER_H
