// Copyright (c) 2018 Stephan Unverwerth
// This code is licensed under MIT license (See LICENSE for details)

#ifndef Strela_Ast_AstIsExpr_h
#define Strela_Ast_AstIsExpr_h

#include "Expr.h"

namespace Strela {
    class TypeExpr;
    class IsExpr: public Expr {
    public:
        IsExpr(Expr* target, TypeExpr* typeExpr): Expr(), target(target), typeExpr(typeExpr) {}
        STRELA_GET_TYPE(Strela::IsExpr, Strela::Expr);
        STRELA_IMPL_EXPR_VISITOR;

    public:
        int typeTag;
        Expr* target;
        TypeExpr* typeExpr;
    };
}

#endif