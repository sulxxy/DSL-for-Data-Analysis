//
// Created by zhiwei on 7/1/18.
//

#include "DSLASTVisitor.h"
#include "DataSource.h"
#include "ForListStmt.h"
#include "clang/AST/OperationKinds.h"
#include "Filter.h"

DSLASTVisitor::DSLASTVisitor(ASTContext *Context) : Context(Context) {
    elementListDict = new vector<ForListStmt *>;
    varList = new vector<Variable>;
    filter = new Filter;
    databag = new DataBag(DB_EMPTY, "DEFAULT");
}

DSLASTVisitor::DSLASTVisitor(ASTContext *Context, DataSource *dataSource) : Context(Context) {
    elementListDict = new vector<ForListStmt *>;
    varList = new vector<Variable>;
    filter = new Filter;
    this->dataSource = new DataSource(dataSource);
}

void DSLASTVisitor::setDataSource(DataSource *dataSource) {
    this->dataSource = new DataSource(dataSource);
}

bool DSLASTVisitor::VisitForStmt(ForStmt *stmt) {
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
//    llvm::outs() << "got if" << "\n";
    Expression *expression = new Expression;
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
            expression->setComparator(cond->getOpcode());
            Expr *lhs = cond->getLHS();
            lhs->dump();
            if (isa<MemberExpr>(lhs)) {
                MemberExpr *memberExpr = cast<MemberExpr>(lhs);
                string className, memberName;
                visitMemberExpr(memberExpr, &className, &memberName);
                llvm::outs() << "got MEM: " << memberName << "\n";
                databag->setColumnArg(memberName);
                expression->setLeftVar(new Variable(INTEGER, memberName)); //todo: datatype
            } else if (isa<ImplicitCastExpr>(lhs)) {
                ImplicitCastExpr *implicitCastExpr = cast<ImplicitCastExpr>(lhs);
                string var;
                visitImplicitCastExpr(implicitCastExpr, &var);
//                llvm::outs() << var << "\n";
                databag->setColumnArg(var);
                expression->setLeftVar(new Variable(INTEGER, var));
            } else {
                llvm::outs() << "Unexpected Expr: " << lhs->getStmtClassName() << "\n";
            }
            Expr *rhs = cond->getRHS();
            if(isa<IntegerLiteral>(rhs)){
                IntegerLiteral *integerLiteral = cast<IntegerLiteral>(rhs);
                string r_val = to_string((int)integerLiteral->getValue().roundToDouble());
//                llvm::outs() << r_val << "\n";
                expression->setRightVar(new Variable(INTEGER, r_val));
            }
//            rhs->dump();
        } else {
            llvm::outs() << "Unexpected IF-COND Expr: " << stmt->getCond()->getStmtClassName() << "\n";
            exit(0);
        }
    } else {
        llvm::outs() << "Exception encountered while processing if-condition" << "\n";
    }
    filter->append(*expression, NONE);
    return true;
}

bool DSLASTVisitor::VisitCallExpr(CallExpr* callExpr){
    if (callExpr == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
//    callExpr->dump();

    string funcName = callExpr->getDirectCallee()->getNameInfo().getAsString();
//    llvm::outs() << "funcName: " << funcName << "\n";

//    callExpr->getArg(0)->dump();
    ImplicitCastExpr *tmp = cast<ImplicitCastExpr>(*(callExpr->getArg(0)->child_begin()));
    StringRef arg0 = cast<StringLiteral>(*(tmp->child_begin()))->getString();
//    tmp->dump();
//    string arg0 = "AGE";

    if(funcName == "groupBy"){
        this->databag = new DataBag(DB_GROUPBY, arg0);
    }
    else if(funcName == "sortBy"){
        this->databag = new DataBag(DB_SORTBY, arg0);
    }
    else if(funcName == "sum"){
        this->databag = new DataBag(DB_SUM, arg0);
    }
    else if(funcName == "average"){
        this->databag = new DataBag(DB_AVG, arg0);
    }
    else{
        this->databag = new DataBag(DB_UNKNOWNARG, arg0);
    }
    return true;
}

bool DSLASTVisitor::VisitVarDecl(VarDecl* varDecl){
    llvm::outs() << "got var decl.\n";
    varDecl->dump();
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
    if (isa<MemberExpr>(*(expr->child_begin()))){
        MemberExpr *memberExpr = cast<MemberExpr>(*(expr->child_begin()));
        string className, memberName;
        visitMemberExpr(memberExpr, &className, &memberName);
        *var = memberName;
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
    //todo
    return true;
}

vector<ForListStmt*> *DSLASTVisitor::getElementListDict(){
    return this->elementListDict;
}

Filter *DSLASTVisitor::getFilter(){
    return this->filter;
}
DataBag* DSLASTVisitor::getDataBag(){
    return this->databag;
}
