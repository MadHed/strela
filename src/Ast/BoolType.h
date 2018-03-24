// Copyright (c) 2018 Stephan Unverwerth
// This code is licensed under MIT license (See LICENSE for details)

#ifndef Strela_Ast_BoolType_h
#define Strela_Ast_BoolType_h

#include "TypeDecl.h"

namespace Strela {
    class BoolType: public TypeDecl {
    public:
        BoolType(): TypeDecl("bool") {}
        STRELA_GET_TYPE(Strela::BoolType, Strela::TypeDecl);
        STRELA_IMPL_STMT_VISITOR;

    public:
        static BoolType instance;
    };
}

#endif