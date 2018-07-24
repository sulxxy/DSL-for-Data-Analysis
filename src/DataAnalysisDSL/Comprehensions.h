//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_COMPREHENSIONS_H
#define LLVM_COMPREHENSIONS_H

#include <vector>
#include "DataBag.h"
#include "Variable.h"
#include "Filter.h"
#include "ForListStmt.h"

using namespace std;

class Comprehensions {
public:
    Comprehensions(vector<ForListStmt*> *listVars, Filter* filter1, DataBag *bag1);
    void feed(DataBag& databag);
    string toString();
    bool setDataBag(DataBag *dataBag);

private:
    vector<ForListStmt*> *vars;
    Filter *filter; //todo: make it a function pointer
    vector<Variable> *heads;
    DataBag *bag;
    DataBagOperator dataBagOperator;
};


#endif //LLVM_COMPREHENSIONS_H
