//
// Created by zhiwei on 7/23/18.
//

#include "Expression.h"
#include "utils.h"

Expression::Expression(Variable *left, Variable *right, Comparator comparator){
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
Comparator Expression::getComparator(){
    return this->comparator;

}
