//
// Created by zhiwei on 6/18/18.
//

#include <iostream>
#include <llvm/Support/raw_ostream.h>
#include "clang/AST/RecursiveASTVisitor.h"

using namespace std;
using namespace clang;

typedef enum{
    DEBUG,
    INFO,
    DATAFLOW
} DebugLevel;

void print(DebugLevel debugLevel, const Stmt *stmt, const string s){
    switch (debugLevel){
        case DEBUG:
            stmt->dump();
            llvm::outs() << s << "\n";
            break;
        case INFO:
            llvm::outs() << s << "\n";
            break;
        case DATAFLOW:
            break;
    }
}
