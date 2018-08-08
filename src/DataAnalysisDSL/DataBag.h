//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_DATABAG_H
#define LLVM_DATABAG_H


#include <string>

using namespace std;

typedef enum{
    DB_CONSTRUCTOR,
    DB_MAP,
    DB_FLATTENMAP,
    DB_GROUPBY,
    DB_WITHFILTER,
    DB_MINUS,
    DB_PLUS,
    DB_FOLD,
    DB_EMPTY,
    DB_SORTBY,
    DB_SUM,
    DB_AVG,
    DB_UNKNOWNARG
} DataBagOperator;

class DataBag {
private:
    int data;
    DataBagOperator dataBagOperator;
    string columnArg;
    string aggregationFunction;

public:
    DataBag();
    DataBag(DataBagOperator dataBagOperator1, string arg0);
    DataBagOperator getDataBagOperator();
    string getColumnArg();
    bool setColumnArg(string arg0);

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
    string getAggreationFunction();

    string toString();
};


#endif //LLVM_DATABAG_H
