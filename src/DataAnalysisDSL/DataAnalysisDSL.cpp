#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

using namespace clang;

class FindNamedClassVisitor
        : public RecursiveASTVisitor<FindNamedClassVisitor> {
public:
    explicit FindNamedClassVisitor(ASTContext *Context)
            : Context(Context) {}

//    bool VisitCXXRecordDecl(CXXRecordDecl *Declaration) {
//        llvm::outs() << "QulifiedName: "
//                     << Declaration->getQualifiedNameAsString() << "\n";
//        if (Declaration->getQualifiedNameAsString() == "n::m::C") {
//            FullSourceLoc FullLocation = Context->getFullLoc(Declaration->getLocStart());
//            if (FullLocation.isValid())
//                llvm::outs() << "Found declaration at "
//                             << FullLocation.getSpellingLineNumber() << ":"
//                             << FullLocation.getSpellingColumnNumber() << "\n";
//        }
//        return true;
//    }

    bool VisitStmt(Stmt* stmt){
        if(isa<DeclRefExpr>(stmt)){
            llvm::outs() << "got declref expr. Do nothing." << "\n";
        }
        return true;
    }

    bool VisitFunctionDecl(FunctionDecl *FD) {
        if (Context->getSourceManager().isInMainFile(FD->getLocation())) {
            Stmt *stmt = FD->getBody();
            if (stmt != NULL) {
                for (StmtIterator bg = stmt->child_begin(), end = stmt->child_end(); bg != end; bg++) {
                    Stmt *cur_stmt = *bg;
                    if (isa<ForStmt>(cur_stmt)) {
                        llvm::outs() << "-----got For------" << "\n";
                        ForStmt *forStmt = cast<ForStmt>(cur_stmt);
                        for (StmtIterator bg1 = forStmt->getBody()->child_begin(), ed1 = forStmt->getBody()->child_end(); bg1 != ed1; bg1++){
                            Stmt *cur_sub_stmt = *bg1;
                            llvm::outs() << "-----got stmt------" << "\n";
                            if(isa<BinaryOperator>(cur_sub_stmt)){
                                llvm::outs() << "-----got binary operator------" << "\n";
                                BinaryOperator *bo = cast<BinaryOperator>(cur_sub_stmt);
                                for (StmtIterator bg2 = bo->child_begin(), ed2 = bo->child_end(); bg2 != ed2; bg2++){
                                    Stmt *cur_exp = *bg2;
                                    llvm::outs() << "-----got Expression------" << "\n";
                                    if(isa<DeclRefExpr>(cur_exp)){
                                        DeclRefExpr *declRefExpr = cast<DeclRefExpr>(cur_exp);
                                        llvm::outs() << "-----got Declref Expression------"
                                                        << declRefExpr->getNameInfo().getAsString()
                                                        << "\n";
                                        declRefExpr->dump();
                                    }
                                }
                            }
                        }
                    }
                    else if (isa<IfStmt>(cur_stmt)) {
                        IfStmt *ifStmt = cast<IfStmt>(cur_stmt);
                        llvm::outs() << "-----got IF------" << "\n";
                        ifStmt->dump();
                    }
                    else if (isa<DeclStmt>(cur_stmt)){
                        DeclStmt *declStmt = cast<DeclStmt>(cur_stmt);
                        llvm::outs() << "-----got declaration------" << "\n";
                        declStmt->dump();

                    }
                    else if (isa<ExprWithCleanups>(cur_stmt)){
                        ExprWithCleanups  *exprWithCleanups = cast<ExprWithCleanups>(cur_stmt);
                        llvm::outs() << "-----got ExprWithCleanups------" << "\n";
                        exprWithCleanups->dump();
                    }
                    else{
                        llvm::outs() << "UKN: "
                                        << cur_stmt->getStmtClassName()
                                        << "\n";
                    }
                }
            }
            llvm::outs() << "Function name: "
                         << FD->getQualifiedNameAsString() << "\n";
        }
        return true;
    }

//    bool TraverseDecl(Decl *D){
//        llvm::outs() << "got declaration. Do nothing." << "\n";
//        return true;
//    }


private:
    ASTContext *Context;
};

class FindNamedClassConsumer : public clang::ASTConsumer {
public:
    explicit FindNamedClassConsumer(ASTContext *Context)
            : Visitor(Context) {}

    virtual void HandleTranslationUnit(clang::ASTContext &Context) {
        Visitor.TraverseDecl(Context.getTranslationUnitDecl());
    }

private:
    FindNamedClassVisitor Visitor;
};

class FindNamedClassAction : public clang::ASTFrontendAction {
public:
    virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
            clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
        return std::unique_ptr<clang::ASTConsumer>(
                new FindNamedClassConsumer(&Compiler.getASTContext()));
    }
};

int main(int argc, char **argv) {
    llvm::outs() << "file: " << argv[1] << "\n";
    if (argc > 1) {
        clang::tooling::runToolOnCode(new FindNamedClassAction, argv[1]);
    }
}