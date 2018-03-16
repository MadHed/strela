#ifndef Strela_Ast_AstBinopExpr_h
#define Strela_Ast_AstBinopExpr_h

#include "Expr.h"

namespace Strela {

    class BinopExpr: public Expr {
    public:
        BinopExpr(const Token& startToken, Expr* left, Expr* right): Expr(startToken), left(left), right(right) {}
        STRELA_GET_TYPE(Strela::BinopExpr, Strela::Expr);
        STRELA_IMPL_EXPR_VISITOR;

    public:
        Expr* left;
        Expr* right;
    };
}

#endif