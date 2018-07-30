//
// Created by zhiwei on 7/1/18.
//

#include "JsonGenerator.h"
#include "utils.h"

JsonGenerator::JsonGenerator(){
    QUERY_PLAN = "QUERY_PLAN";
    OPERATOR_NAME = "OPERATOR_NAME";
    LEFT_CHILD = "LEFT_CHILD";
    RIGHT_CHILD = "RIGHT_CHILD";
    PREDICATE = "PREDICATE";
    PREDICATES = "PREDICATES";
    PREDICATE_TYPE = "PREDICATE_TYPE ";
    ATTRIBUTE_REFERENCE = "ATTRIBUTE_REFERENCE";
    COLUMN_NAME = "COLUMN_NAME";
    TABLE_NAME = "TABLE_NAME";
    VERSION = "VERSION";
    PREDICATE_COMPARATOR = "PREDICATE_COMPARATOR";
    CONSTANT = "CONSTANT";
    CONSTANT_VALUE = "CONSTANT_VALUE";
    CONSTANT_TYPE = "CONSTANT_TYPE";
    LEFT_HAND_SIDE_ATTRIBUTE_REFERENCE = "LEFT_HAND_SIDE_ATTRIBUTE_REFERENCE";
    RESULT_NAME = "RESULT_NAME";
    RIGHT_HAND_SIDE_ATTRIBUTE_REFERENCE = "RIGHT_HAND_SIDE_ATTRIBUTE_REFERENCE";
    AGGREGATION_SPECIFICATION = "AGGREGATION_SPECIFICATION ";
    AGGREGATION_FUNCTION = "AGGREGATION_FUNCTION ";
    GROUPING_COLUMNS = "GROUPING_COLUMNS";
    JsonWriter = new Writer<StringBuffer>(sb);
}


bool JsonGenerator::templateParsing(const char* json){
    this->d.Parse(json);
    return true;
}

bool JsonGenerator::exportFilterAsPredicate(Writer<StringBuffer> *writer, Filter *filter){
    if(writer == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if(filter == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    

}

bool JsonGenerator::exportComprehensionsAsJson(Comprehensions *comprehensions1){
    if(comprehensions1 == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    {
        JsonWriter->StartObject();
        JsonWriter->Key(QUERY_PLAN);
        {
            JsonWriter->StartObject();
            JsonWriter->Key(OPERATOR_NAME);
            JsonWriter->String(OPERATOR_NAME);//todo: give an operator_name
            JsonWriter->Key(PREDICATE);
            {
                JsonWriter->StartObject();
                JsonWriter->Key(PREDICATE_TYPE);
                JsonWriter->String(PREDICATE_TYPE); //todo: predicate type
                JsonWriter->Key(PREDICATES);
                JsonWriter->String(PREDICATES); //todo: array
                JsonWriter->EndObject();
            }

            JsonWriter->Key(LEFT_CHILD);
            {
                JsonWriter->StartObject();
                JsonWriter->EndObject();
            }

            JsonWriter->Key(RIGHT_CHILD);
            {
                JsonWriter->StartObject();
                JsonWriter->EndObject();
            }

            JsonWriter->EndObject();
        }

        JsonWriter->EndObject();
    }

    return true;
}
