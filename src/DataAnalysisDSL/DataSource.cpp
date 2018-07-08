//
// Created by zhiwei on 6/18/18.
//

#include "DataSource.h"

DataSource::DataSource(){
    descriptor = new vector<Variable>;
}

DataSource::DataSource(DataSource *dataSource) {
    *descriptor = dataSource->getDescription();
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

