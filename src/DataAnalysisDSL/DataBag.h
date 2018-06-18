//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_DATABAG_H
#define LLVM_DATABAG_H


class DataBag {
private:
    int data;

public:
    DataBag();

    void map();

    void flattenMap();

    void groupBy();

    void withFilter();

    void minus();

    void plus();

    void fold();

    void empty();

};


#endif //LLVM_DATABAG_H
