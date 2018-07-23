//
// Created by zhiwei on 7/23/18.
//

#include "Expression.h"
#include "utils.h"

Expression::Expression() {

}

Expression::Expression(Variable *left, Variable *right, BO_Opcode comparator){
    if(left == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    if(right == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    this->leftVar = left;
    this->rightVar = right;
    this->comparator = comparator;
}

Variable* Expression::getLeftVar(){
    return this->leftVar;
}
Variable* Expression::getRightVar(){
    return this->rightVar;

}
BO_Opcode Expression::getComparator(){
    return this->comparator;
}

bool Expression::setLeftVar(Variable *var){
    if(var == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    this->leftVar = var;
    return true;
}

bool Expression::setRightVar(Variable *var){
    if(var == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    this->rightVar = var;
    return true;
}

bool Expression::setComparator(BO_Opcode comparator1){
    this->comparator = comparator1;
    return true;

}
