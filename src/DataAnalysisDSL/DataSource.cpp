//
// Created by zhiwei on 6/18/18.
//

#include <llvm/Support/raw_ostream.h>
#include "DataSource.h"

DataSource::DataSource(){
    descriptor = new vector<Variable>;
}

DataSource::DataSource(DataSource *dataSource) {
    if(dataSource == NULL){
        llvm::outs() << "empty pointer" << "\n";
    }
    else{
        *descriptor = dataSource->getDescription();
    }
}

bool DataSource::buildConnection() {
    return true;
}

vector<Variable> DataSource::getDescription() {
    return *descriptor;
}

bool DataSource::readData() {
    return true;
}

