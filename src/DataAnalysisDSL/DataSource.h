//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_DATASOURCE_H
#define LLVM_DATASOURCE_H

#include "Variable.h"

class DataSource {
private:
    vector<Variable> *descriptor;
public:
    DataSource();
    DataSource(DataSource*);
    vector<Variable> getDescription();
    bool readData();
    bool buildConnection();

};


#endif //LLVM_DATASOURCE_H
