//
// Created by zhiwei on 7/8/18.
//

#ifndef LLVM_LISTADT_H
#define LLVM_LISTADT_H


#include <string>
#include "clang/AST/RecursiveASTVisitor.h"
#include "Variable.h"

using namespace clang;

class ForListStmt{
private:
    Variable element;
    Variable list;
    SourceRange sourceRange;

public:
    ForListStmt(Variable *ele, Variable *list, SourceRange sourceRange1);

    string getListName();
    string getElementName();
    Variable getListVar();
    Variable getElementVar();
    SourceRange getSourceRange();

};

#endif //LLVM_LISTADT_H
