// Copyright (c) 2018 Stephan Unverwerth
// This code is licensed under MIT license (See LICENSE for details)

#ifndef Strela_Ast_TypeType_h
#define Strela_Ast_TypeType_h

#include "TypeDecl.h"

namespace Strela {
    class TypeType: public TypeDecl {
    public:
        TypeType(): TypeDecl("Type") {}
        STRELA_GET_TYPE(Strela::TypeType, Strela::TypeDecl);
        STRELA_IMPL_STMT_VISITOR;

    public:
        static TypeType instance;
    };
}

#endif