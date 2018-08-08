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
    JsonGenerator();
    bool templateParsing(const char* );
    bool exportFilterAsPredicate(Writer<StringBuffer> *writer, Filter *filter);
    bool exportComprehensionsAsJson(Comprehensions *comprehensions1);
    bool exportExprAsPredicate(Writer<StringBuffer> *writer, Expression *expression);
    bool exportDataBagAsAggregation(Writer<StringBuffer> *writer, DataBag *dataBag);

private:
    Document d;
    StringBuffer sb;
    Writer<StringBuffer>* JsonWriter;
    Comprehensions *comprehensions;

    const char* QUERY_PLAN;
    const char* OPERATOR_NAME;
    const char* LEFT_CHILD;
    const char* RIGHT_CHILD;
    const char* PREDICATE;
    const char* PREDICATES;
    const char* PREDICATE_TYPE;
    const char* ATTRIBUTE_REFERENCE;
    const char* ATTRIBUTES;
    const char* COLUMN_NAME;
    const char* TABLE_NAME;
    const char* VERSION;
    const char* PREDICATE_COMPARATOR;
    const char* CONSTANT;
    const char* CONSTANT_VALUE;
    const char* CONSTANT_TYPE;
    const char* LEFT_HAND_SIDE_ATTRIBUTE_REFERENCE;
    const char* RESULT_NAME;
    const char* RESULT_VAL;
    const char* RIGHT_HAND_SIDE_ATTRIBUTE_REFERENCE;
    const char* AGGREGATION_SPECIFICATION;
    const char* GROUPING_COLUMNS;
    const char* AGGREGATION_FUNCTION;
    const char* AND_PREDICATE;
    const char* COLUMN_CONSTANT_PREDICATE;
    const char* COLUMN_COLUMN_PREDICATE;
    const char* TABLE_SCAN;

};

#endif //LLVM_JSONGENERATOR_H
