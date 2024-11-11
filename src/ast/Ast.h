#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Lexer.h"
#include "Node.h"

namespace flashdb
{
    class Ast
    {
    private:
        Token m_CurrentToken;
        std::unique_ptr<Lexer> m_Lexer;
        std::unique_ptr<Node> m_Root;
    public:
        Ast(std::unique_ptr<Lexer> lexer);
    public:
        bool Next();
        Node GetRoot() const;
        std::string ToString() const;
    private:
        void ParseSelect();
        void ParseInsert();
        void Advance();
        void ExpectValue(const std::string& value);
        Token ExpectType(const TokenType& type);
    };
}
