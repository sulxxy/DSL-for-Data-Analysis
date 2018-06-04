# DSL for Data Analysis
A Domain Specific Language for Data Analysis written in C++ with LLVM as back-end 

# Description
The appeal of MapReduce has spawned a family of systems that implement or extend it. In order to enable parallel collection processing with User-Defined Functions (UDFs), these systems expose extensions of the MapReduce programming model as library-based dataflow APIs that are tightly coupled to their underlying runtime engine. Expressing data analysis algorithms with complex data and control flow structure using such APIs reveals a number of limitations that impede programmer’s productivity.

In this project, this problem is tackled by applying the ideas of Emma [1] that are summarized in a presentation [2] and a paper [3]. The idea is to use compiler framework LLVM and build a DSL in C++ instead of Scala. As a backend, this project will use the LLVM compiler [4].

# Tool Chains
* llvm (&clang) 7.0
* Boost::Phoenix 3.2.0

# Deliverables
* A concept and implementation of a C++ based DSL implementation
* An evaluation and benchmark using queries of the TPC-H benchmark [5]

# Presentations
* [Initial Discussion](https://docs.google.com/presentation/d/1qKCc-usSp4yyKjJsFRIqfw5l5ffWULwigyTIkNzoBO8/edit?usp=sharing)
* Middle Term Presentation: TBA
* Final Presentation: TBA

# supplementary Materials 
* [Understanding Clang AST](https://jonasdevlieghere.com/understanding-the-clang-ast/)
* [Match The Clang AST](https://clang.llvm.org/docs/LibASTMatchers.html)
* [Implement Source2Source Clang Tool](http://www.voidcn.com/article/p-tpecfzhv-os.html)


# References
* [1] http://emma-language.org/
* [2] [Emma Introduction Slides](https://docs.google.com/presentation/d/1IM6VhGGg--dx5dEnCJtWkD0JXCl9Sw-wzTgr3Cj6uig/edit#slide=id.g1e346bc9de_0_6)
* [3] http://aalexandrov.name/assets/pdf/2015.SIGMOD.ImplicitParallelism.pdf
* [4] https://llvm.org/
* [5] http://www.tpc.org/tpch/
