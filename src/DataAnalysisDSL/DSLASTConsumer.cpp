//
// Created by zhiwei on 7/1/18.
//

#include "DSLASTConsumer.h"
#include "DataSource.h"
#include "JsonGenerator.h"

DSLASTConsumer::DSLASTConsumer(ASTContext *Context) : Visitor(Context){

}

DSLASTConsumer::DSLASTConsumer(ASTContext *Context, DataSource *datasource)
        : Visitor(Context) {
    this->dataSource = datasource;
}

void DSLASTConsumer::HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.setDataSource(dataSource);
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
//    llvm::outs() << "building comprehensions" << "\n";
    comprehensions = new Comprehensions(Visitor.getElementListDict(), Visitor.getFilter(), Visitor.getDataBag());
//    llvm::outs() << "\n" + comprehensions->toString() << "\n";
    JsonGenerator* jsonGenerator = new JsonGenerator;
    jsonGenerator->exportComprehensionsAsJson(comprehensions);
}
