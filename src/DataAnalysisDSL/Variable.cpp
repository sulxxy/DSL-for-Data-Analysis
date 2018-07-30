//
// Created by zhiwei on 7/8/18.
//

#include "Variable.h"
#include "utils.h"

Variable::Variable() {
    var = new pair<BasicDataType, string>();
}

Variable::Variable(BasicDataType dt, string name) {
    var = new pair<BasicDataType, string>(dt, name);
}

Variable::Variable(Variable *var) {
    Variable(var->getVarType(), var->getVarName());
}

string Variable::getVarName() {
    if(var == NULL){
        cout << "Empty pointer. Exit. \n";
        return NULL;
    }
    else{
        return var->second;
    }
}

BasicDataType Variable::getVarType() {
    if(var == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        return ERROR;
    }
    return var->first;
}


string Variable::getVarTypeAsString() {
    if(var == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        return "ERROR";
    }
    switch (var->first){
        case INTEGER:
            return "INT";
        case DOUBLE:
            return "DOUBLE";
        case FLOAT:
            return "FLOAT";
        case STRING:
            return "VCHAR";
        case CHAR:
            return "CHAR";
        case CONSTANT:
            return "CONSTANT";
        default:
            return "UNK";
    }
}

