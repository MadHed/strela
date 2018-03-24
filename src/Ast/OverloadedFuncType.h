// Copyright (c) 2018 Stephan Unverwerth
// This code is licensed under MIT license (See LICENSE for details)

#ifndef Strela_Ast_OverloadedFuncType_h
#define Strela_Ast_OverloadedFuncType_h

#include "TypeDecl.h"

namespace Strela {
    class OverloadedFuncType: public TypeDecl {
    public:
        OverloadedFuncType(): TypeDecl("$overloaded") {}
        STRELA_GET_TYPE(Strela::OverloadedFuncType, Strela::TypeDecl);
        STRELA_IMPL_STMT_VISITOR;

    public:
        static OverloadedFuncType instance;
    };
}

#endif