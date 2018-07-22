//
// Created by zhiwei on 7/8/18.
//

#include <string>
#include "ForListStmt.h"


ForListStmt::ForListStmt(Variable *ele, Variable *list, SourceRange sourceRange1) {
    if(ele == NULL || list == NULL){
        cout << "Empty pointer. Exit. " << "\n";
        exit(0);
    }
    this->element = *ele;
    this->list = *list;
    this->sourceRange = sourceRange1;
}

SourceRange ForListStmt::getSourceRange() {return sourceRange;}

string ForListStmt::getElementName() {return element.getVarName();}

Variable ForListStmt::getListVar(){
    return list;

}
Variable ForListStmt::getElementVar(){
    return element;

}

string ForListStmt::getListName() {return list.getVarName();}
