//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_COMPREHENSIONS_H
#define LLVM_COMPREHENSIONS_H

#include <vector>
#include "DataBag.h"


class Comprehensions {
public:
    Comprehensions();
    void feed(DataBag& databag);

private:
    std::vector<int> xs;
    int filters;
    int head;
    DataBag bag;

};


#endif //LLVM_COMPREHENSIONS_H
