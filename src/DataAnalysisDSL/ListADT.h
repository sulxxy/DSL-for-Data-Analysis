//
// Created by zhiwei on 7/8/18.
//

#ifndef LLVM_LISTADT_H
#define LLVM_LISTADT_H


#include <string>
#include "Variable.h"

class ListADT {
private:
    Variable element;
    Variable list;

public:
    ListADT(Variable *ele, Variable *list);

    string getListName();
    string getElementName();

};


#endif //LLVM_LISTADT_H
