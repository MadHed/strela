#include "ArrayType.h"
#include "FieldDecl.h"
#include "IdTypeExpr.h"
#include "IntType.h"

namespace Strela {
    ArrayType* ArrayType::get(TypeDecl* base) {
        auto it = arrayTypes.find(base);
        if (it != arrayTypes.end()) return it->second;
        auto atype = new ArrayType(base->name + "[]", base);
        atype->lengthField = new FieldDecl("length", new IdTypeExpr("int"));
        atype->lengthField->type = atype->lengthField->typeExpr->type = &IntType::instance;
        atype->lengthField->index = 0;
        arrayTypes.insert(std::make_pair(base, atype));
        return atype;
    }

    Node* ArrayType::getMember(const std::string& name) {
        return name == "length" ? lengthField : nullptr;
    }
}