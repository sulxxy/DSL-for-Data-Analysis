add_clang_executable(find-class-decls
	main.cpp
	DataBag.h
	DataBag.cpp
    DataSource.h
	DataSource.cpp
    Comprehensions.h
	Comprehensions.cpp
	JsonGenerator.h
	JsonGenerator.cpp
	DSLASTConsumer.h
	DSLASTConsumer.cpp
	DSLASTFrontendAction.h
	DSLASTFrontendAction.cpp
	DSLASTVisitor.h
	DSLASTVisitor.cpp
	utils.cpp
)

target_link_libraries(find-class-decls 
	PRIVATE
	clangTooling
)

