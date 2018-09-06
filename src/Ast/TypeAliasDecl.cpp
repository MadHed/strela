#include "TypeAliasDecl.h"
#include "Expr.h"

namespace Strela {
	Node* TypeAliasDecl::getMember(const std::string& name) {
		return typeExpr->type->getMember(name);
	}

	std::vector<Node*> TypeAliasDecl::getMethods(const std::string& name) {
		return typeExpr->type->getMethods(name);
	}
}
