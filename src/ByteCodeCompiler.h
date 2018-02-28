#ifndef Strela_ByteCodeCompiler_h
#define Strela_ByteCodeCompiler_h

#include "NodeVisitor.h"

#include <string>
#include <map>

namespace Strela {
    class ByteCodeChunk;

    class ByteCodeCompiler: public NodeVisitor {
    public:
        ByteCodeCompiler(ByteCodeChunk&);

        void visit(AstModDecl&) override;
        void visit(AstFuncDecl&) override;
        void visit(AstParam&) override;
        void visit(AstVarDecl&) override;
        void visit(AstIdExpr&) override;
        void visit(AstRetStmt&) override;
        void visit(AstLitExpr&) override;
        void visit(AstBlockStmt&) override;
        void visit(AstCallExpr&) override;
        void visit(AstExprStmt&) override;
        void visit(AstBinopExpr&) override;
        void visit(AstClassDecl&) override;
        void visit(AstScopeExpr&) override;
        void visit(AstIfStmt&) override;
        void visit(AstFieldDecl&) override;
        void visit(AstNewExpr&) override;
        void visit(AstAssignExpr&) override;
        void visit(AstIdTypeExpr&) override;
        void visit(AstWhileStmt&) override;
        void visit(AstPostfixExpr&) override;
        void visit(AstArrayTypeExpr&) override {}
        void visit(AstImportStmt&) override {}
        void visit(AstUnaryExpr&) override;

    private:
        bool tryCompileAsConst(AstExpr& n);
        void error(AstNode& node, const std::string& msg);

    private:
        std::map<int, AstFuncDecl*> functionFixups;
        AstFuncDecl* function = nullptr;

    public:
        ByteCodeChunk& chunk;
    };
}
#endif