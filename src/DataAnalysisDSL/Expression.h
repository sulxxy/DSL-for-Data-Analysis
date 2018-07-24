//
// Created by zhiwei on 7/23/18.
//

#ifndef LLVM_EXPRESSION_T_H
#define LLVM_EXPRESSION_T_H

#include "Variable.h"
#include "clang/AST/RecursiveASTVisitor.h"

using namespace clang;

typedef BinaryOperator::Opcode BO_Opcode;

class Expression {
public:
    Expression();
    Expression(Variable *left, Variable *right, BO_Opcode comparator);

    Variable* getLeftVar();
    Variable* getRightVar();
    BO_Opcode getComparator();

    bool setLeftVar(Variable *var);
    bool setRightVar(Variable *var);
    bool setComparator(BO_Opcode comparator1);

    string opcodeStr();

    string toString();

private:
    Variable *leftVar;
    Variable *rightVar;
    BO_Opcode comparator;
};


#endif //LLVM_EXPRESSION_T_H
