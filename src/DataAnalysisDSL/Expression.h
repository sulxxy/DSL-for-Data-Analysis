//
// Created by zhiwei on 7/23/18.
//

#ifndef LLVM_EXPRESSION_T_H
#define LLVM_EXPRESSION_T_H

#include "Variable.h"

typedef enum{
    EQ,
    NEQ,
    LEQ,
    GEQ,
    GT,
    LT
}Comparator;

class Expression {
public:
    Expression(Variable *left, Variable *right, Comparator comparator);

    Variable* getLeftVar();
    Variable* getRightVar();
    Comparator getComparator();

private:
    Variable *leftVar;
    Variable *rightVar;
    Comparator comparator;
};


#endif //LLVM_EXPRESSION_T_H
