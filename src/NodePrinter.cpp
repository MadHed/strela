#include "NodePrinter.h"
#include "Ast/nodes.h"

#include <iostream>

namespace Strela {
    void NodePrinter::visit(ModDecl& n) {
        std::cout << "module " << n.name << " {\n";
        push();
        for (auto&& en: n.enums) {
            std::cout << indent;
            visitChild(en);
        }
        for (auto&& cls: n.classes) {
            std::cout << indent;
            visitChild(cls);
        }
        for (auto&& fun: n.functions) {
            std::cout << indent;
            visitChild(fun);
        }
        pop();
        std::cout << "}\n";
    }

    void NodePrinter::visit(ClassDecl& n) {
        if (n.isExported) {
            std::cout << "export ";
        }
        std::cout << "class " << n.name << " {\n";
        push();
        for (auto&& field: n.fields) {
            std::cout << indent;
            visitChild(field);
        }
        for (auto&& fun: n.methods) {
            std::cout << indent;
            visitChild(fun);
        }
        pop();
        std::cout << indent << "}\n";
    }

    void NodePrinter::visit(FuncDecl& n) {
        if (n.isExported) {
            std::cout << "export ";
        }
        std::cout << "function " << n.name << "(";
        for(auto&& param: n.params) {
            visitChild(param);
            if (&param != &n.params.back()) {
                std::cout << ", ";
            }
        }
        std::cout << "): ";
        visitChild(n.returnTypeExpr);
        std::cout << " {\n";
        push();
        for (auto&& stmt: n.stmts) {
            std::cout << indent;
            visitChild(stmt);
        }
        pop();
        std::cout << indent << "}\n";
    }

    void NodePrinter::visit(BlockStmt& n) {
        std::cout << "{\n";
        push();
        for (auto&& stmt: n.stmts) {
            std::cout << indent;
            visitChild(stmt);
        }
        pop();
        std::cout << indent << "}\n";
    }

    void NodePrinter::visit(Param& n) {
        std::cout << n.name << ": ";
        visitChild(n.typeExpr);
    }

    void NodePrinter::visit(VarDecl& n) {
        std::cout << "var " << n.name;
        if (n.typeExpr) {
            std::cout << ": ";
            visitChild(n.typeExpr);
        }
        if (n.initializer) {
            std::cout << " = ";
            visitChild(n.initializer);
        }
        std::cout << ";\n";
    }

    void NodePrinter::visit(IdExpr& n) {
        std::cout << n.name;
    }

    void NodePrinter::visit(ExprStmt& n) {
        visitChild(n.expression);
        std::cout << ";\n";
    }

    void NodePrinter::visit(CallExpr& n) {
        visitChild(n.callTarget);
        std::cout << "(";
        for (auto&& arg: n.arguments) {
            arg->accept(*this);
            if (&arg != &n.arguments.back()) {
                std::cout << ", ";
            }
        }
        std::cout << ")";
    }

    void NodePrinter::visit(RetStmt& n) {
        std::cout << "return ";
        if (n.expression) {
            visitChild(n.expression);
        }
        std::cout << ";\n";

    }

    std::string escape(const std::string&);

    void NodePrinter::visit(LitExpr& n) {
        if (n.token.type == TokenType::String) {
            std::cout << "\"" << escape(n.token.value) << "\"";
        }
        else {
            std::cout << n.token.value;
        }
    }

    void NodePrinter::visit(BinopExpr& n) {
        visitChild(n.left);
        std::cout << " " << getTokenVal(n.op) << " ";
        visitChild(n.right);
    }

    void NodePrinter::visit(ScopeExpr& n) {
        visitChild(n.scopeTarget);
        std::cout << "." << n.name;
    }

    void NodePrinter::visit(IfStmt& n) {
        std::cout << "if (";
        visitChild(n.condition);
        std::cout << ") ";
        visitChild(n.trueBranch);
        if (n.falseBranch) {
            std::cout << "else ";
            visitChild(n.falseBranch);
        }
    }

    void NodePrinter::visit(FieldDecl& n) {
        std::cout << "var " << n.name << ": ";
        visitChild(n.typeExpr);
        std::cout << ";\n";
    }

    void NodePrinter::visit(NewExpr& n) {
        std::cout << "new ";
        visitChild(n.typeExpr);
    }

    void NodePrinter::visit(AssignExpr& n) {
        visitChild(n.left);
        std::cout << " = ";
        visitChild(n.right);
    }

    void NodePrinter::visit(IdTypeExpr& n) {
        std::cout << n.name;
    }

    void NodePrinter::visit(WhileStmt& n) {
        std::cout << "while (";
        visitChild(n.condition);
        std::cout << ") ";
        visitChild(n.body);
    }

    void NodePrinter::visit(PostfixExpr& n) {
        visitChild(n.target);
        std::cout << getTokenVal(n.op);
    }

    void NodePrinter::visit(ArrayTypeExpr& n) {
        visitChild(n.base);
        std::cout << "[]";
    }

    void NodePrinter::visit(ImportStmt& n) {
        std::cout << "import ";
        for (auto&& part: n.parts) {
            std::cout << part;
            if (&part != &n.parts.back()) {
                std::cout << ".";
            }
        }
        if (n.all) std::cout << ".*";
        std::cout << ";\n";
    }

    void NodePrinter::visit(UnaryExpr& n) {
        std::cout << getTokenVal(n.op);
        visitChild(n.target);
    }

    void NodePrinter::visit(EnumDecl& n) {
        std::cout << (n.isExported ? "export " : "") << "enum {\n";
        push();
        for (auto&& el: n.elements) {
            std::cout << indent;
            visitChild(el);
        }
        pop();
        std::cout << indent <<  "}\n";
    }

    void NodePrinter::visit(InterfaceDecl& n) {
        std::cout << (n.isExported ? "export " : "") << "interface {\n";
        push();
        for (auto&& m: n.methods) {
            std::cout << indent;
            visitChild(m);
        }
        pop();
        std::cout << indent << "}\n";
    }

    void NodePrinter::visit(InterfaceMethodDecl& n) {
        std::cout << "function " << n.name << "(";
        for(auto&& param: n.params) {
            visitChild(param);
            if (&param != &n.params.back()) {
                std::cout << ", ";
            }
        }
        std::cout << "): ";
        visitChild(n.returnTypeExpr);
        std::cout << ";\n";
    }

    void NodePrinter::visit(EnumElement& n) {
        std::cout << n.name << ",\n";
    }

    void NodePrinter::visit(ThisExpr& n) {
        std::cout << "this";
    }

    void NodePrinter::visit(CastExpr& n) {
        std::cout << "cast<";
        n.targetType->name;
        std::cout << ">(";
        visitChild(n.sourceExpr);
        std::cout << ")";
    }

    void NodePrinter::push() {
        ++indentation;
        indent = std::string(indentation * 4, ' ');
    }

    void NodePrinter::pop() {
        --indentation;
        indent = std::string(indentation * 4, ' ');
    }

}