//
// Created by zhiwei on 7/8/18.
//

#ifndef LLVM_LISTADT_H
#define LLVM_LISTADT_H


class ListADT {
private:
    Variable element;
    Variable list;

public:
    ListADT();

    string getListName();
    string getElementName();

};


#endif //LLVM_LISTADT_H
