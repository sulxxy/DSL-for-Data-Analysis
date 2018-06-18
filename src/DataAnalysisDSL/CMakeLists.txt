add_clang_executable(find-class-decls
    DataAnalysisDSL.cpp
	DataBag.cpp
    Comprehensions.cpp
	utils.cpp
)

target_link_libraries(find-class-decls 
	PRIVATE
	clangTooling
)

