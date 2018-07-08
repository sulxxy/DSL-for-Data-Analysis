//
// Created by zhiwei on 7/1/18.
//

#include "DSLASTVisitor.h"
#include "DataSource.h"

DSLASTVisitor::DSLASTVisitor(ASTContext *Context): Context(Context) {
    elementListDict = new StrStrMap_t;
    varList = new vector<Variable>;
}

DSLASTVisitor::DSLASTVisitor(ASTContext *Context, DataSource *dataSource): Context(Context) {
    elementListDict = new StrStrMap_t;
    varList = new vector<Variable>;
    this->dataSource = new DataSource(dataSource);
}

void DSLASTVisitor::setDataSource(DataSource *dataSource) {
    this->dataSource = new DataSource(dataSource);
}

bool DSLASTVisitor::VisitCXXForRangeStmt(CXXForRangeStmt *stmt){
    if(stmt == NULL){
        llvm::outs() << "empty pointer at line " << __LINE__ << ", exit." << "\n";
        exit(0);
    }
    string loopVar = stmt->getLoopVariable()->getNameAsString();
    Expr *init_expr = stmt->getRangeInit();
    DeclRefExpr *ref_init_expr = cast<DeclRefExpr>(init_expr);
    string loopList = ref_init_expr->getNameInfo().getAsString();
    elementListDict->insert(StrStrPair_t(loopVar, loopList));

    return true;
}

bool DSLASTVisitor::VisitIfStmt(IfStmt *stmt) {
    if(stmt->getInit() != NULL){
        llvm::outs() << "Init: " << stmt->getInit()->getStmtClassName() << "\n";
    }
    else if(stmt->getCond() != NULL) {
        llvm::outs() << "Cond: " << stmt->getCond()->getStmtClassName() << "\n";
        if(isa<BinaryOperator>(stmt->getCond())){
            BinaryOperator *cond = cast<BinaryOperator>(stmt->getCond());
            Expr *lhs = cond->getLHS();
            if(isa<MemberExpr>(lhs)){
                MemberExpr *memberExpr = cast<MemberExpr>(lhs);
                string className, memberName;
                visitMemberExpr(memberExpr, &className, &memberName);
            }
            else if (isa<ImplicitCastExpr>(lhs)){
                ImplicitCastExpr *implicitCastExpr = cast<ImplicitCastExpr>(lhs);
                string var;
                visitImplicitCastExpr(implicitCastExpr, &var);
                llvm::outs() << var << "\n";
            }
            else{
                llvm::outs() << "Unexpected Expr: " << lhs->getStmtClassName() << "\n";
            }
        }
        else{
            llvm::outs() << "Unexpected IF-COND Expr: " << stmt->getCond()->getStmtClassName() << "\n";
            exit(0);
        }
    }
    else{
        llvm::outs() << "Exception encountered while processing if-condition" << "\n";
    }
//    llvm::outs() << stmt->getInit()->getStmtClassName() << "\n";
    return true;
}

bool DSLASTVisitor::visitImplicitCastExpr(ImplicitCastExpr *expr, string *var) {
    if(isa<DeclRefExpr>(*(expr->child_begin()))){
        DeclRefExpr *declRefExpr = cast<DeclRefExpr>(*(expr->child_begin()));
        *var = declRefExpr->getNameInfo().getAsString();
    }
    return true;
}

bool DSLASTVisitor::visitMemberExpr(MemberExpr *expr, string *className, string *memeberName) {
    llvm::outs() << "member name: " << expr->getMemberNameInfo().getAsString() << "\n";
    *memeberName = expr->getMemberNameInfo().getAsString();
    if(isa<DeclRefExpr>(expr->getBase())){
        DeclRefExpr *declRefExpr = cast<DeclRefExpr>(expr->getBase());
        llvm::outs() << "class name: " << declRefExpr->getNameInfo().getAsString()<< "\n";
        *className = declRefExpr->getNameInfo().getAsString();
    }
    return true;
}

