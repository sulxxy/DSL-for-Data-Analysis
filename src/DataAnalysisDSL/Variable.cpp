//
// Created by zhiwei on 7/8/18.
//

#include "Variable.h"

Variable::Variable() {
    var = new pair<BasicDataType, string>();
}

Variable::Variable(BasicDataType dt, string name) {
    var = new pair<BasicDataType, string>(dt, name);
}

Variable::Variable(Variable *var) {
    this(var->getVarType(), var->getVarName());
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
        cout << "Empty pointer. Exit. \n";
        return NULL;
    }
    return var->first;
}


