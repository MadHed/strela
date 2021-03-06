// Copyright (c) 2018 Stephan Unverwerth
// This code is licensed under MIT license (See LICENSE for details)

#ifndef Strela_Ast_AstGenericParam_h
#define Strela_Ast_AstGenericParam_h

#include "TypeDecl.h"

namespace Strela {
    class GenericParam: public TypeDecl {
    public:
        STRELA_GET_TYPE(Strela::GenericParam, Strela::TypeDecl);
    };
}

#endif