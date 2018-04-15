// Copyright (c) 2018 Stephan Unverwerth
// This code is licensed under MIT license (See LICENSE for details)

#ifndef Strela_Ast_AstBinopExpr_h
#define Strela_Ast_AstBinopExpr_h

#include "Expr.h"

namespace Strela {

    class BinopExpr: public Expr {
    public:
        BinopExpr(TokenType op, Expr* left, Expr* right): Expr(), op(op), left(left), right(right) {}
        STRELA_GET_TYPE(Strela::BinopExpr, Strela::Expr);
        STRELA_IMPL_EXPR_VISITOR;

    public:
        TokenType op;
        Expr* left;
        Expr* right;
        FuncDecl* function = nullptr;
    };
}

#endif