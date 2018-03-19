#ifndef Strela_Ast_AstArrayTypeExpr_h
#define Strela_Ast_AstArrayTypeExpr_h

#include "TypeExpr.h"

namespace Strela {

    class ArrayTypeExpr: public TypeExpr {
    public:
        ArrayTypeExpr(TypeExpr* base): TypeExpr(), base(base) {}
        STRELA_GET_TYPE(Strela::ArrayTypeExpr, Strela::TypeExpr);
        STRELA_IMPL_TYPE_EXPR_VISITOR;

    public:
        TypeExpr* base;
    };
}

#endif