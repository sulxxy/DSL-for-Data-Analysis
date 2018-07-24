//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_DATABAG_H
#define LLVM_DATABAG_H


#include <string>

using namespace std;

typedef enum{
    CONSTRUCTOR,
    MAP,
    FLATTENMAP,
    GROUPBY,
    WITHFILTER,
    MINUS,
    PLUS,
    FOLD,
    EMPTY,
    SORTBY,
    UNKNOWNARG
} DataBagOperator;

class DataBag {
private:
    int data;
    DataBagOperator dataBagOperator;
    string arg;

public:
    DataBag();
    DataBag(DataBagOperator dataBagOperator1, string arg0);

    bool map();
    bool flattenMap();
    bool groupBy();
    bool withFilter();
    bool minus();
    bool plus();
    bool fold();
    bool empty();
    bool collect(int );
    bool executeDataBagAPI(DataBagOperator);

    bool setDataBagOperator(DataBagOperator);

    string toString();
};


#endif //LLVM_DATABAG_H
