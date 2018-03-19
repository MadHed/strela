#ifndef Strela_Ast_FuncType_h
#define Strela_Ast_FuncType_h

#include "TypeDecl.h"

#include <vector>

namespace Strela {
    class FuncType: public TypeDecl {
    public:
        FuncType(const std::string& name): TypeDecl(name) {}
        STRELA_GET_TYPE(Strela::FuncType, Strela::TypeDecl);
        STRELA_IMPL_STMT_VISITOR;

        static FuncType* get(TypeDecl* returnType, const std::vector<TypeDecl*>& paramTypes);

    public:
        std::vector<TypeDecl*> paramTypes;
        TypeDecl* returnType;

        static std::vector<FuncType*> funcTypes;
    };
}

#endif