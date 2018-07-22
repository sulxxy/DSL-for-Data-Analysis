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
    AND
} LogicOperator;


class Filter {
public:
    Filter(vector<Expression> *conditions, vector<LogicOperator> *connectors);
//    string toString();

private:
    vector<Expression> *conditions;
    vector<LogicOperator> *connectors;
};


#endif //LLVM_FILTER_H
