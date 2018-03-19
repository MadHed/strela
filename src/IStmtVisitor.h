#ifndef Strela_IStmtVisitor_h
#define Strela_IStmtVisitor_h

namespace Strela {
    class ModDecl;
    class FuncDecl;
    class Param;
    class VarDecl;
    class RetStmt;
    class BlockStmt;
    class ExprStmt;
    class ClassDecl;
    class IfStmt;
    class FieldDecl;
    class WhileStmt;
    class ImportStmt;
    class EnumDecl;
    class EnumElement;
    class ArrayType;
    class ClassDecl;
    class EnumDecl;
    class FloatType;
    class FuncType;
    class IntType;
    class ModDecl;
    class NullType;
    class VoidType;
    class BoolType;
    class OverloadedFuncType;
    class TypeType;
    class InvalidType;
    class InterfaceMethodDecl;
    class InterfaceDecl;

    class IStmtVisitor {
    public:
        virtual void visit(ModDecl&) = 0;
        virtual void visit(ImportStmt&) = 0;
        virtual void visit(FuncDecl&) = 0;
        virtual void visit(Param&) = 0;
        virtual void visit(VarDecl&) = 0;
        virtual void visit(ClassDecl&) = 0;
        virtual void visit(FieldDecl&) = 0;
        virtual void visit(EnumDecl&) = 0;
        virtual void visit(EnumElement&) = 0;
        virtual void visit(InterfaceDecl&) = 0;
        virtual void visit(InterfaceMethodDecl&) = 0;

        virtual void visit(RetStmt&) = 0;
        virtual void visit(BlockStmt&) = 0;
        virtual void visit(ExprStmt&) = 0;
        virtual void visit(IfStmt&) = 0;
        virtual void visit(WhileStmt&) = 0;

        // builtin types
        virtual void visit(ArrayType&) {}
        virtual void visit(FloatType&) {}
        virtual void visit(FuncType&) {}
        virtual void visit(IntType&) {}
        virtual void visit(NullType&) {}
        virtual void visit(VoidType&) {}
        virtual void visit(BoolType&) {}
        virtual void visit(TypeType&) {}
        virtual void visit(InvalidType&) {}
        virtual void visit(OverloadedFuncType&) {}
    };
}

#endif