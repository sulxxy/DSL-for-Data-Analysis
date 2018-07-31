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
    AND_PREDICATE = "AND_PREDICATE";
    COLUMN_CONSTANT_PREDICATE = "COLUMN_CONSTANT_PREDICATE";
    COLUMN_COLUMN_PREDICATE = "COLUMN_COLUMN_PREDICATE";
    TABLE_SCAN = "TABLE_SCAN";
    JsonWriter = new Writer<StringBuffer>(sb);
}


bool JsonGenerator::templateParsing(const char* json){
    this->d.Parse(json);
    return true;
}

bool JsonGenerator::exportExprAsPredicate(Writer<StringBuffer> *writer, Expression *expr){
    if(writer == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if(expr == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    writer->StartObject();
    writer->Key(PREDICATE);
    {
        writer->StartObject();
        writer->Key(PREDICATE_TYPE);
        writer->String(COLUMN_CONSTANT_PREDICATE);
        writer->Key(ATTRIBUTE_REFERENCE);
        {
            writer->StartObject();
            writer->Key(COLUMN_NAME);
            writer->String(COLUMN_NAME); //todo: define column_name_val
            writer->Key(TABLE_NAME);
            writer->String(TABLE_NAME); //todo: define column_name_val
            writer->Key(VERSION);
            writer->Int(1);
            writer->Key(RESULT_NAME);
            writer->String(RESULT_NAME); //todo: result name
            writer->EndObject();
        }
        writer->Key(PREDICATE_COMPARATOR);
        writer->String(expr->getOpcodeAsString().c_str());
        writer->Key(CONSTANT);
        {
            writer->StartObject();
            writer->Key(CONSTANT_VALUE);
            writer->String(expr->getRightVarNameAsString().c_str());
            writer->Key(CONSTANT_TYPE);
            writer->String(expr->getRightVarTypeAsString().c_str());
            writer->EndObject();
        }
        writer->EndObject();
    }
    writer->EndObject();
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

    writer->Key(PREDICATE);
    {
        writer->StartObject();
        writer->Key(PREDICATE_TYPE);
        writer->String(AND_PREDICATE); //todo: predicate type
        writer->Key(PREDICATES);
        writer->StartArray();
        for(int i = 0; i < filter->size(); i++){
            exportExprAsPredicate(JsonWriter, &(filter->getConditions()->at(i)));
        }
        writer->EndArray();
        writer->EndObject();
    }
    return true;
}

bool JsonGenerator::exportDataBagAsAggregation(Writer<StringBuffer> *writer, DataBag *dataBag){
    if(writer == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    if(dataBag == NULL){
        ErrorMsg(__FILE__, __func__, __LINE__, NULLPOINTER);
        exit(0);
    }

    writer->Key(GROUPING_COLUMNS);
    writer->StartArray();
    for(int i = 0;i < 1; i++){  //todo:
        writer->StartObject();
        writer->Key(ATTRIBUTE_REFERENCE);
        {
            writer->StartObject();
            writer->Key(COLUMN_NAME);
            writer->String(dataBag->getColumnArg().c_str());
            writer->Key(TABLE_NAME);
            writer->String(TABLE_NAME);
            writer->Key(VERSION);
            writer->Int(1);
            writer->Key(RESULT_NAME);
            writer->String(RESULT_NAME); // todo: give a result name
            writer->EndObject();
        }
        writer->EndObject();
    }
    writer->EndArray();
    if(dataBag->getAggreationFunction() != "EMPTY") {
        writer->Key(AGGREGATION_SPECIFICATION);
        writer->StartArray();
        for (int i = 0; i < 1; i++) {
            writer->StartObject();
            writer->Key(AGGREGATION_FUNCTION);
            writer->String(dataBag->getAggreationFunction().c_str());
            writer->Key(ATTRIBUTE_REFERENCE);
            {
                writer->StartObject();
                writer->Key(COLUMN_NAME);
                writer->String(COLUMN_NAME); //todo: give a column name
                writer->Key(TABLE_NAME);
                writer->String(TABLE_NAME);
                writer->Key(VERSION);
                writer->Int(1);
                writer->Key(RESULT_NAME);
                writer->String(RESULT_NAME); // todo: give a result name
                writer->EndObject();
            }
            writer->EndObject();
        }
        writer->EndArray();
    }

    return true;
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
            exportFilterAsPredicate(JsonWriter, comprehensions1->getFilter());
            if(comprehensions1->getDataBag()->getDataBagOperator() != EMPTY){
                exportDataBagAsAggregation(JsonWriter, comprehensions1->getDataBag());
            }
            JsonWriter->Key(LEFT_CHILD);
            {
                JsonWriter->StartObject();
                JsonWriter->Key(OPERATOR_NAME);
                JsonWriter->String(TABLE_SCAN);
                JsonWriter->Key(TABLE_NAME);
                JsonWriter->String(TABLE_NAME);   //todo: give a name
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

    llvm::outs() <<  sb.GetString() << "\n";
    return true;
}
