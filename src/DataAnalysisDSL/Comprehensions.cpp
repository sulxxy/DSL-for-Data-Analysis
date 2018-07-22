//
// Created by zhiwei on 6/18/18.
//

#include "Comprehensions.h"
#include "utils.h"

Comprehensions::Comprehensions(vector<ForListStmt> *listVars, Filter* filter1){
    if(listVars == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if(filter1 == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if(heads == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    this->vars = listVars;
    this->filter = filter1;
    this->heads = new vector<Variable>;

    for(int i = 0; i < listVars->size(); i++){
        heads->push_back(listVars->at(i).getElementVar());
    }
}
