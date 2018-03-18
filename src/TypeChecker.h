#ifndef Strela_TypeChecker_h
#define Strela_TypeChecker_h

#include "IStmtVisitor.h"
#include "IExprVisitor.h"


#include <string>
#include <vector>

namespace Strela {
    class TypeDecl;
    class Node;
    class Stmt;
    class Expr;

    class TypeChecker: public IStmtVisitor, public IExprVisitor {
    public:
        TypeChecker();

        void visit(ModDecl&) override;
        void visit(FuncDecl&) override;
        void visit(VarDecl&) override;
        void visit(IdExpr&) override;
        void visit(RetStmt&) override;
        void visit(LitExpr&) override;
        void visit(BlockStmt&) override;
        void visit(CallExpr&) override;
        void visit(ExprStmt&) override;
        void visit(BinopExpr&) override;
        void visit(ClassDecl&) override;
        void visit(ScopeExpr&) override;
        void visit(IfStmt&) override;
        void visit(NewExpr&) override;
        void visit(AssignExpr&) override;
        void visit(WhileStmt&) override;
        void visit(PostfixExpr&) override;
        void visit(UnaryExpr&) override;

        void visit(FieldDecl&) override {}
        void visit(IdTypeExpr&) override {}
        void visit(ArrayTypeExpr&) override {}
        void visit(ImportStmt&) override {}
        void visit(EnumDecl&) override {}
        void visit(EnumElement&) override {}
        void visit(Param&) override {}

        template<typename T> void visitChildren(T& children) {
            for (auto&& child: children) {
                child->accept(*this);
            }
        }

        template<typename T> void visitChild(T& child) {
            child->accept(*this);
        }

    private:
		FuncDecl* findOverload(Expr* target, const std::vector<TypeDecl*>& argtypes);
        void error(Node& node, const std::string& msg);
        void warning(Node& node, const std::string& msg);

        FuncDecl* function = nullptr;
        BlockStmt* block = nullptr;
        ClassDecl* _class = nullptr;

        bool returns = false;
    };
}
#endif