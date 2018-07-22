//
// Created by zhiwei on 7/19/18.
//
#include "utils.h"

void ErrorMsg(const char* file, const char* func, int line, Error_e e){

    switch (e){
        case NULLPOINTER:
            llvm::outs() << "Empty pointer at file: " << file
                         << ", function: " << func
                         << ", line: " << line
                         << "\n";
            break;
        case UNKNOWN:
            llvm::outs() << "Unknown error at file: " << file
                         << ", function: " << func
                         << ", line: " << line
                         << "\n";
            break;
    }
}
