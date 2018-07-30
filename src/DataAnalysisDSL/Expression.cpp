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

string Expression::opcodeStr(){
    switch(this->comparator){
        case BO_LE:
            return "<=";
        case BO_LT:
            return "<";
        case BO_GT:
            return ">";
        case BO_GE:
            return ">=";
        case BO_EQ:
            return "==";
        default:
            return "BO_UNK";
    }
}

string Expression::toString(){
    return this->leftVar->getVarName() + " " + opcodeStr() + " " + this->rightVar->getVarName();
}

string Expression::getOpcodeAsString(){
    switch(this->comparator){
        case BO_LE:
            return "LESS_EQUAL";
        case BO_LT:
            return "LESS_THAN";
        case BO_GT:
            return "GREATER_THAN";
        case BO_GE:
            return "GREATER_EQUAL";
        case BO_EQ:
            return "EQUAL";
        default:
            return "BO_UNK";
    }
}

string Expression::getLeftVarNameAsString(){
    return getLeftVar()->getVarName();
}

string Expression::getLeftVarTypeAsString(){
    return getLeftVar()->getVarTypeAsString();
}

string Expression::getRightVarNameAsString(){
    return getRightVar()->getVarName();
}

string Expression::getRightVarTypeAsString(){
    return getRightVar()->getVarTypeAsString();
}
