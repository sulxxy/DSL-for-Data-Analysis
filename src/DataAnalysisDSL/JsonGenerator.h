//
// Created by zhiwei on 7/1/18.
//

#ifndef LLVM_JSONGENERATOR_H
#define LLVM_JSONGENERATOR_H

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Comprehensions.h"

using namespace std;
using namespace rapidjson;

class JsonGenerator {
public:
    const char* QUERY_PLAN;
    const char* OPERATOR_NAME;
    const char* LEFT_CHILD;
    const char* RIGHT_CHILD;
    const char* PREDICATE;
    const char* PREDICATES;
    const char* PREDICATE_TYPE;
    const char* ATTRIBUTE_REFERENCE;
    const char* COLUMN_NAME;
    const char* TABLE_NAME;
    const char* VERSION;
    const char* PREDICATE_COMPARATOR;
    const char* CONSTANT;
    const char* CONSTANT_VALUE;
    const char* CONSTANT_TYPE;
    const char* LEFT_HAND_SIDE_ATTRIBUTE_REFERENCE;
    const char* RESULT_NAME;
    const char* RIGHT_HAND_SIDE_ATTRIBUTE_REFERENCE;
    const char* AGGREGATION_SPECIFICATION;
    const char* GROUPING_COLUMNS;
    const char* AGGREGATION_FUNCTION;
    JsonGenerator();
    bool templateParsing(const char* );
    bool exportFilterAsPredicate(Writer<StringBuffer> *writer, Filter *filter);
    bool exportComprehensionsAsJson(Comprehensions *comprehensions1);

private:
    Document d;
    StringBuffer sb;
    Writer<StringBuffer>* JsonWriter;
    Comprehensions *comprehensions;
};

#endif //LLVM_JSONGENERATOR_H
