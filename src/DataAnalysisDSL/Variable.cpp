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


string Variable::getVarName() {
    if(var == NULL){
       return NULL;
    }
    else{
        return var->second;
    }
}


