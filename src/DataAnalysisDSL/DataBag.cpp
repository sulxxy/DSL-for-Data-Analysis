//
// Created by zhiwei on 6/18/18.
//

#include "DataBag.h"

DataBag::DataBag() {

}

bool DataBag::map() {

}

bool DataBag::flattenMap() {

}

bool DataBag::groupBy() {

}

bool DataBag::withFilter() {

}

bool DataBag::minus() {

}

bool DataBag::plus() {

}

bool DataBag::fold() {

}

bool DataBag::empty() {

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
    }
}
