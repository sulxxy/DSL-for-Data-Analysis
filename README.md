# DSL for Scalable Data Analysis
A Domain Specific Language for scalable data analysis written in C++ with LLVM as back-end 

# Description
The appeal of MapReduce has spawned a family of systems that implement or extend it. In order to enable parallel collection processing with User-Defined Functions (UDFs), these systems expose extensions of the MapReduce programming model as library-based dataflow APIs that are tightly coupled to their underlying runtime engine. Expressing data analysis algorithms with complex data and control flow structure using such APIs reveals a number of limitations that impede programmer’s productivity.

In this project, this problem is tackled by applying the ideas of Emma [1] that are summarized in a presentation [2] and a paper [3]. The idea is to use compiler framework LLVM and build a DSL in C++ instead of Scala. As a backend, this project will use the LLVM compiler [4].

# Tool Chains
* llvm (&clang) 7.0
* [RapidJSON](http://rapidjson.org/)

## How to run
* Download latest llvm and clang source code ( see [here](https://clang.llvm.org/get_started.html))
* `git clone $DSL_for_Data_Analysis`
* `cp $DSL-for-Data-Analysis/src/DataAnalysisDSL $LLVM/tools/clang/examples`
* add DataAnalysisDSL directory to CMakeList.txt
* `cp $RAPIDJSON/include/rapidjson $LLVM/include`
* `mkdir build (out of $LLVM)`
* `cd build && cmake -G "unix Makefiles" -DCLANG_BUILD_EXAMPLES=1 ../llvm`
* `make`
* `$build/bin/data_analysis_dsl input_code or ("$(cat path_to_input_file)")`

# Deliverables
* A concept and implementation of a C++ based DSL implementation
* An evaluation and benchmark using queries of the TPC-H benchmark [5]

# Presentations
* [Midterm Presentation](https://docs.google.com/presentation/d/1qKCc-usSp4yyKjJsFRIqfw5l5ffWULwigyTIkNzoBO8/edit?usp=sharing)
* [Final Presentation](https://docs.google.com/presentation/d/1Srj1zN6jqBpNtd-ldUAT3MBW31Vv5foNe4vy5PaZscY/edit?usp=sharing)

# Supplementary Materials 
* [Understanding Clang AST](https://jonasdevlieghere.com/understanding-the-clang-ast/)
* [Match The Clang AST](https://clang.llvm.org/docs/LibASTMatchers.html)
* [Implement Source2Source Clang Tool](http://www.voidcn.com/article/p-tpecfzhv-os.html)


# References
* [1] http://emma-language.org/
* [2] [Emma Introduction Slides](https://docs.google.com/presentation/d/1IM6VhGGg--dx5dEnCJtWkD0JXCl9Sw-wzTgr3Cj6uig/edit#slide=id.g1e346bc9de_0_6)
* [3] http://aalexandrov.name/assets/pdf/2015.SIGMOD.ImplicitParallelism.pdf
* [4] https://llvm.org/
* [5] http://www.tpc.org/tpch/
