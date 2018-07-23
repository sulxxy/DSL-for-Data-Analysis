//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_DATABAG_H
#define LLVM_DATABAG_H

typedef enum{
    CONSTRUCTOR,
    MAP,
    FLATTENMAP,
    GROUPBY,
    WITHFILTER,
    MINUS,
    PLUS,
    FOLD,
    EMPTY
} DataBagOperator;

class DataBag {
private:
    int data;
    DataBagOperator dataBagOperator;

public:
    DataBag();

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
};


#endif //LLVM_DATABAG_H