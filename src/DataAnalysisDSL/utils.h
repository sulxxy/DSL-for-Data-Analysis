//
// Created by zhiwei on 6/18/18.
//

#ifndef LLVM_UTILS_H
#define LLVM_UTILS_H

#include <llvm/Support/raw_ostream.h>

using namespace std;

typedef enum{
    DEBUG,
    INFO,
    DATAFLOW
} DebugLevel;

typedef enum{
    NULLPOINTER,
    UNKNOWN,
}Error_e;

/*
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
 */

void ErrorMsg(const char* file, const char* func, int line, Error_e e);


#endif
