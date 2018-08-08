//
// Created by zhiwei on 6/18/18.
//

#include "DataBag.h"

DataBag::DataBag() {
    dataBagOperator = DB_CONSTRUCTOR;
}

DataBag::DataBag(DataBagOperator dataBagOperator1, string arg0){
    dataBagOperator = dataBagOperator1;
    columnArg = arg0;
    switch (dataBagOperator){
        case DB_EMPTY:
            aggregationFunction = "EMPTY";
        case DB_SUM:
            aggregationFunction = "SUM";
        case DB_AVG:
            aggregationFunction = "AVG";
        default:
            aggregationFunction = "DB_UNK";
    }
}

bool DataBag::setColumnArg(string arg0){
    columnArg = arg0;
}

bool DataBag::map() {

    return true; }

bool DataBag::flattenMap() {

    return true;
}

bool DataBag::groupBy() {

    return true;
}

bool DataBag::withFilter() {

    return true;
}

bool DataBag::minus() {

    return true;
}

bool DataBag::plus() {

    return true;
}

bool DataBag::fold() {

    return true;
}

bool DataBag::empty() {
    return true;
}

bool DataBag::executeDataBagAPI(DataBagOperator dataBagOperator) {
    switch(dataBagOperator){
        case DB_CONSTRUCTOR:
            return true;
        case DB_MAP:
            return map();
        case DB_FLATTENMAP:
            return flattenMap();
        case DB_WITHFILTER:
            return withFilter();
        case DB_GROUPBY:
            return groupBy();
        case DB_MINUS:
            return minus();
        case DB_PLUS:
            return plus();
        case DB_FOLD:
            return fold();
        case DB_EMPTY:
            return empty();
        default:
            return true;
    }
}

bool DataBag::setDataBagOperator(DataBagOperator dataBagOperator1){
    this->dataBagOperator = dataBagOperator1;
    return true;
}

bool DataBag::collect(int x) {
    /* TODO */
    return true;
}

string DataBag::toString(){
    /* TODO */
    switch(dataBagOperator){
        case DB_GROUPBY:
            return "\ngroupBy " + columnArg + "\n";
        case DB_SORTBY:
            return "\norderBy " + columnArg + "\n";
    }
}
string DataBag::getAggreationFunction(){
    return aggregationFunction;
}

DataBagOperator DataBag::getDataBagOperator(){
    return dataBagOperator;
}

string DataBag::getColumnArg(){
    return columnArg;
}
