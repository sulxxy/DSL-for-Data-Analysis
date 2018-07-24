//
// Created by zhiwei on 7/23/18.
//

#ifndef LLVM_FILTER_H
#define LLVM_FILTER_H

#include <vector>
#include <string>

#include "Expression.h"

using namespace std;

typedef enum{
    OR,
    AND,
    NONE
} LogicOperator;


class Filter {
public:
    Filter();
    Filter(vector<Expression> *conditions, vector<LogicOperator> *connectors);
    bool append(Expression condition, LogicOperator connector);
    string toString();

private:
    vector<Expression> *conditions;
    vector<LogicOperator> *connectors;
};


#endif //LLVM_FILTER_H
