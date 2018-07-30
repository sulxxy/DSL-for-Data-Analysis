//
// Created by zhiwei on 7/8/18.
//

#ifndef LLVM_DATATYPE_H
#define LLVM_DATATYPE_H

#include <iostream>
#include <vector>
using namespace std;

typedef enum{
    ERROR=-1,
    INTEGER,
    DOUBLE,
    FLOAT,
    STRING,
    CHAR,
    CONSTANT
}BasicDataType;

class Variable{
private:
    pair<BasicDataType, string> *var;

public:
    Variable();
    Variable(BasicDataType, string);
    Variable(Variable *var);
    string getVarName();
    BasicDataType getVarType();
    string getVarTypeAsString();


};

#endif //LLVM_DATATYPE_H
