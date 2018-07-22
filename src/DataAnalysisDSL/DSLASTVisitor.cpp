//
// Created by zhiwei on 7/1/18.
//

#include "DSLASTVisitor.h"
#include "DataSource.h"
#include "ForListStmt.h"

DSLASTVisitor::DSLASTVisitor(ASTContext *Context) : Context(Context) {
    elementListDict = new vector<ForListStmt *>;
    varList = new vector<Variable>;
    comprehensions = new Comprehensions;
}

DSLASTVisitor::DSLASTVisitor(ASTContext *Context, DataSource *dataSource) : Context(Context) {
    elementListDict = new vector<ForListStmt *>;
    varList = new vector<Variable>;
    this->dataSource = new DataSource(dataSource);
}

void DSLASTVisitor::setDataSource(DataSource *dataSource) {
    this->dataSource = new DataSource(dataSource);
}

bool DSLASTVisitor::VisitForStmt(ForStmt *stmt) {
    llvm::outs() << "got for" << "\n";
    if (stmt == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    return true;
}

bool DSLASTVisitor::VisitCXXForRangeStmt(CXXForRangeStmt *stmt) {
    if (stmt == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    Variable *loopVar = new Variable(STRING, stmt->getLoopVariable()->getNameAsString());
    Expr *init_expr = stmt->getRangeInit();
    DeclRefExpr *ref_init_expr = cast<DeclRefExpr>(init_expr);
    Variable *loopList = new Variable(STRING, ref_init_expr->getNameInfo().getAsString());
    elementListDict->push_back(new ForListStmt(loopVar, loopList, stmt->getSourceRange()));
    return true;
}

bool DSLASTVisitor::VisitIfStmt(IfStmt *stmt) {
    llvm::outs() << "got if" << "\n";
    if (stmt == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    if (stmt->getInit() != NULL) {
        llvm::outs() << "Init: " << stmt->getInit()->getStmtClassName() << "\n";
    } else if (stmt->getCond() != NULL) {
        llvm::outs() << "Cond: " << stmt->getCond()->getStmtClassName() << "\n";
        if (isa<BinaryOperator>(stmt->getCond())) {
            BinaryOperator *cond = cast<BinaryOperator>(stmt->getCond());
            Expr *lhs = cond->getLHS();
            if (isa<MemberExpr>(lhs)) {
                MemberExpr *memberExpr = cast<MemberExpr>(lhs);
                string className, memberName;
                visitMemberExpr(memberExpr, &className, &memberName);
            } else if (isa<ImplicitCastExpr>(lhs)) {
                ImplicitCastExpr *implicitCastExpr = cast<ImplicitCastExpr>(lhs);
                string var;
                visitImplicitCastExpr(implicitCastExpr, &var);
                llvm::outs() << var << "\n";
            } else {
                llvm::outs() << "Unexpected Expr: " << lhs->getStmtClassName() << "\n";
            }
        } else {
            llvm::outs() << "Unexpected IF-COND Expr: " << stmt->getCond()->getStmtClassName() << "\n";
            exit(0);
        }
    } else {
        llvm::outs() << "Exception encountered while processing if-condition" << "\n";
    }

    return true;
}

bool DSLASTVisitor::VisitCallExpr(CallExpr* callExpr){
    if (callExpr == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    callExpr->dump();

    Expr *expr = callExpr->getCallee();

//    llvm::outs() << callExpr->getDirectCallee()->getNameInfo().getAsString() << "\n";

    if(isa<UserDefinedLiteral>(callExpr)){
        UserDefinedLiteral* userDefinedLiteral = cast<UserDefinedLiteral>(callExpr);
        llvm::outs() << "get literal" << "\n";
    }
    return true;
}

bool DSLASTVisitor::visitImplicitCastExpr(ImplicitCastExpr *expr, string *var) {
    if (expr == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    if (isa<DeclRefExpr>(*(expr->child_begin()))) {
        DeclRefExpr *declRefExpr = cast<DeclRefExpr>(*(expr->child_begin()));
        *var = declRefExpr->getNameInfo().getAsString();
    }
    return true;
}

bool DSLASTVisitor::visitMemberExpr(MemberExpr *expr, string *className, string *memeberName) {
    if (expr == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    llvm::outs() << "member name: " << expr->getMemberNameInfo().getAsString() << "\n";
    *memeberName = expr->getMemberNameInfo().getAsString();
    if (isa<DeclRefExpr>(expr->getBase())) {
        DeclRefExpr *declRefExpr = cast<DeclRefExpr>(expr->getBase());
        llvm::outs() << "class name: " << declRefExpr->getNameInfo().getAsString() << "\n";
        *className = declRefExpr->getNameInfo().getAsString();
    }
    return true;
}

bool DSLASTVisitor::isNested(SourceRange sr1, SourceRange sr2) {
    /* return true if sr2 is nested inside sr1 */
    if (sr1.getBegin() < sr2.getBegin() && sr2.getEnd() < sr1.getEnd()) {
        return true;
    } else {
        return false;
    }
}

bool DSLASTVisitor::findParent(SourceRange sr, vector<ForListStmt*> *list){
    return true;
}

vector<ForListStmt> *DSLASTVisitor::getElementListDict(){
    return this->elementListDict;
}

Filter *DSLASTVisitor::getFilter(){
    return this->filter;
}
