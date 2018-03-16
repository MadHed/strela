#ifndef Strela_Parser_h
#define Strela_Parser_h

#include "Ast/nodes.h"
#include "Ast/Token.h"

#include <vector>
#include <memory>

namespace Strela {
    class Parser {
    public:
        Parser(const std::vector<Token>& tokens): tokens(tokens), token(tokens.begin()) {}

        ModDecl* parseModule();
        IdExpr* parseIdentifierExpression();
        FuncDecl* parseFunction();
        Param* parseParameter();
        VarDecl* parseVarDecl();
        BlockStmt* parseBlockStatement();
        ClassDecl* parseClassDecl();
        FieldDecl* parseFieldDecl();
        EnumDecl* parseEnumDecl();
        ImportStmt* parseImportStmt();

        Stmt* parseStatement();
        RetStmt* parseReturnStatement();
        ExprStmt* parseExprStmt();
        IfStmt* parseIfStmt();
        WhileStmt* parseWhileStmt();

        Expr* parseExpression(int precedence = 0);
        TypeExpr* parseTypeExpr();
        NewExpr* parseNewExpr();
        LitExpr* parseLiteralExpression();
        CallExpr* parseCallExpr(Expr* callTarget);

        bool match(TokenType type);
        bool matchExpr();
        bool matchSecondary();
        bool matchUnary();
        bool matchTypeSecondary();
        bool matchBinary();
        void expect(TokenType type);
        Token eat(TokenType type);
        Token eat();
        bool eof();
        void expected(TokenType expectedType);
        void expected(const std::string& expected);

    private:
        const std::vector<Token>& tokens;
        std::vector<Token>::const_iterator token;

        int numVariables = 0;
    };
}

#endif