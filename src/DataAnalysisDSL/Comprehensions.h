//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_COMPREHENSIONS_H
#define LLVM_COMPREHENSIONS_H

#include <vector>
#include "DataBag.h"
#include "Variable.h"

using namespace std;

class Comprehensions {
public:
    Comprehensions();
    void feed(DataBag& databag);

private:
    vector<Variable> xs;
    int filters;
    Variable *head;
    DataBag *bag;
    DataBagOperator dataBagOperator;
};


#endif //LLVM_COMPREHENSIONS_H
