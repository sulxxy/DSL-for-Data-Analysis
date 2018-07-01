//
// Created by zhiwei on 7/1/18.
//

#ifndef LLVM_DSLASTVISITOR_H
#define LLVM_DSLASTVISITOR_H


#include <string>

#include "clang/AST/RecursiveASTVisitor.h"

using namespace clang;
using namespace std;

typedef map<string, string> StrStrMap_t;
typedef pair<string, string> StrStrPair_t;

class DSLASTVisitor : public RecursiveASTVisitor<DSLASTVisitor> {
public:
    explicit DSLASTVisitor(ASTContext *Context);

    bool VisitCXXForRangeStmt(CXXForRangeStmt *stmt);
    bool VisitIfStmt(IfStmt *stmt);


//    bool VisitFunctionDecl(FunctionDecl *FD);

private:
    ASTContext *Context;
    StrStrMap_t* elementListDict;
    StrStrMap_t* dataTypeDict;

    bool visitImplicitCastExpr(ImplicitCastExpr *expr, string *var);
    bool visitMemberExpr(MemberExpr *expr, string *className, string *memberName);
};

#endif //LLVM_DSLASTVISITOR_H
