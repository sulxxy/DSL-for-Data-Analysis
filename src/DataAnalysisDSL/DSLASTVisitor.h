//
// Created by zhiwei on 7/1/18.
//

#ifndef LLVM_DSLASTVISITOR_H
#define LLVM_DSLASTVISITOR_H


#include <string>

#include "clang/AST/RecursiveASTVisitor.h"
#include "DataSource.h"
#include "ForListStmt.h"
#include "Comprehensions.h"
//#include "utils.h"

using namespace clang;
using namespace std;

class DSLASTVisitor : public RecursiveASTVisitor<DSLASTVisitor> {
public:
    explicit DSLASTVisitor(ASTContext *Context);
    explicit DSLASTVisitor(ASTContext *Context, DataSource *dataSource);

    bool VisitCXXForRangeStmt(CXXForRangeStmt *stmt);
    bool VisitForStmt(ForStmt *stmt);
    bool VisitIfStmt(IfStmt *stmt);
    bool VisitCallExpr(CallExpr* callExpr);

    void setDataSource(DataSource *dataSource);

    bool isNested(SourceRange sr1, SourceRange sr2);
    bool findParent(SourceRange sr, vector<ForListStmt*> *list);

    vector<ForListStmt> *getElementListDict();
    Filter *getFilter();

//    bool VisitFunctionDecl(FunctionDecl *FD);

private:
    ASTContext *Context;
    /* mapping: element -> list */
    vector<ForListStmt> *elementListDict;
    Filter *filter;
    vector<Variable> *varList;
    DataSource *dataSource;
    Comprehensions *comprehensions;

    bool visitImplicitCastExpr(ImplicitCastExpr *expr, string *var);
    bool visitMemberExpr(MemberExpr *expr, string *className, string *memberName);
};

#endif //LLVM_DSLASTVISITOR_H
