// Copyright (c) 2018 Stephan Unverwerth
// This code is licensed under MIT license (See LICENSE for details)

#ifndef Strela_IExprVisitor_h
#define Strela_IExprVisitor_h

namespace Strela {
    class IdExpr;
    class LitExpr;
    class CallExpr;
    class BinopExpr;
    class ScopeExpr;
    class NewExpr;
    class AssignExpr;
    class PostfixExpr;
    class UnaryExpr;
    class ThisExpr;
    class CastExpr;
    class IsExpr;
    class ArrayLitExpr;
    class SubscriptExpr;

    class IExprVisitor {
    public:
        virtual void visit(IdExpr&) = 0;
        virtual void visit(LitExpr&) = 0;
        virtual void visit(CallExpr&) = 0;
        virtual void visit(BinopExpr&) = 0;
        virtual void visit(ScopeExpr&) = 0;
        virtual void visit(NewExpr&) = 0;
        virtual void visit(AssignExpr&) = 0;
        virtual void visit(PostfixExpr&) = 0;
        virtual void visit(UnaryExpr&) = 0;
        virtual void visit(ThisExpr&) = 0;
        virtual void visit(CastExpr&) = 0;
        virtual void visit(IsExpr&) = 0;
        virtual void visit(ArrayLitExpr&) = 0;
        virtual void visit(SubscriptExpr&) = 0;
    };
}

#endif