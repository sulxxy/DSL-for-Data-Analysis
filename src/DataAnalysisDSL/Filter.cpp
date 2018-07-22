//
// Created by zhiwei on 7/23/18.
//

#include "Filter.h"
#include "utils.h"

Filter::Filter(vector<Expression> *conditions, vector<LogicOperator> *connectors){
    if(conditions == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if(connectors == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if(conditions->size() < connectors->size()){
        ErrorMsg(__FILE__, __func__, __LINE__, UNKNOWN);
        exit(0);
    }

    this->conditions = conditions;
    this->connectors = connectors;

}
