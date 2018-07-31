//
// Created by zhiwei on 6/18/18.
//

#include "Comprehensions.h"
#include "utils.h"

Comprehensions::Comprehensions(vector<ForListStmt *> *listVars, Filter *filter1, DataBag *bag1) {
    if (listVars == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if (filter1 == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if (bag1 == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    this->vars = listVars;
    this->filter = filter1;
    this->bag = bag1;
    this->heads = new vector<Variable>;

    for (int i = 0; i < listVars->size(); i++) {
        heads->push_back(listVars->at(i)->getElementVar());
    }
}

bool Comprehensions::setDataBag(DataBag *dataBag) {
    if (dataBag == NULL) {
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }
    this->bag = dataBag;
    return true;
}

string Comprehensions::toString() {
    string queryPlan = "{QUERY_PLAN: ";
    string operatorName = "OPERATOR_NAME: ";
    string leftChild = "LEFT_CHILD: ";
    string rightChild = "RIGHT_CHILD: ";

    string select = "SELECT ";
    string from = " FROM ";
    string where = " WHERE ";

    // todo:
    string ret = select + this->vars->at(0)->getElementName() + from
            + this->vars->at(0)->getListName() + "\n" + where + this->filter->toString();
    if (bag != NULL) {
        ret = ret + bag->toString();
    }
    return ret;

}
Filter* Comprehensions::getFilter(){
    return filter;
}
DataBag* Comprehensions::getDataBag(){
    return this->bag;
}
