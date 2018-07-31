//
// Created by zhiwei on 6/18/18.
//

#include "DataBag.h"

DataBag::DataBag() {
    dataBagOperator = CONSTRUCTOR;
}

DataBag::DataBag(DataBagOperator dataBagOperator1, string arg0){
    dataBagOperator = dataBagOperator1;
    columnArg = arg0;
    aggregationFunction = "EMPTY";
}

bool DataBag::map() {

    return true;
}

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
        case CONSTRUCTOR:
            return true;
        case MAP:
            return map();
        case FLATTENMAP:
            return flattenMap();
        case WITHFILTER:
            return withFilter();
        case GROUPBY:
            return groupBy();
        case MINUS:
            return minus();
        case PLUS:
            return PLUS;
        case FOLD:
            return fold();
        case EMPTY:
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
        case GROUPBY:
            return "\ngroupBy " + columnArg + "\n";
        case SORTBY:
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
