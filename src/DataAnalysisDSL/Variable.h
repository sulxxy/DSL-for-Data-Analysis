//
// Created by zhiwei on 7/8/18.
//

#ifndef LLVM_DATATYPE_H
#define LLVM_DATATYPE_H

#include <iostream>
#include <vector>
using namespace std;

typedef enum{
    INTEGER,
    DOUBLE,
    FLOAT,
    STRING,
    CHAR,
    LIST
}BasicDataType;

class Variable{
private:
    pair<BasicDataType, string> *var;

public:
    Variable();
    Variable(BasicDataType, string);
    string getVarName();


};

#endif //LLVM_DATATYPE_H
