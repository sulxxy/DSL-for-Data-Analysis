//
// Created by zhiwei on 6/18/18.
//

#include "DataSource.h"

DataSource::DataSource(){
    descriptor = new vector<Variable>;
}

DataSource::DataSource(DataSource *dataSource) {
    if(dataSource == NULL){
//        llvm::outs() << "error: " << __FILE__ << "\n";
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
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

