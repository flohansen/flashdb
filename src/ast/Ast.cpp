#include <cstdio>
#include <memory>
#include <stdexcept>

#include "Ast.h"
#include "Lexer.h"
#include "SelectNode.h"
#include "InsertNode.h"

namespace flashdb
{
    Ast::Ast(std::unique_ptr<Lexer> lexer)
        : m_Lexer(std::move(lexer)), m_CurrentToken{}
    {
        this->Advance();

        if (m_CurrentToken.value == "SELECT")
        {
            this->ParseSelect();
        }
        else if (m_CurrentToken.value == "INSERT")
        {
            this->ParseInsert();
        }
    }

    void Ast::ParseSelect()
    {
        auto select_node = std::make_unique<SelectNode>();

        this->ExpectValue("SELECT");

        do
        {
            auto column = this->ExpectType(TokenType::Literal);
            select_node->AddColumn(column.value);

            if (m_CurrentToken.type != TokenType::Comma)
            {
                break;
            }

            this->Advance();
        }
        while (true);

        this->ExpectValue("FROM");

        auto table = this->ExpectType(TokenType::Literal);
        select_node->SetTableName(table.value);

        m_Root = std::move(select_node);
    }

    void Ast::ParseInsert()
    {
        auto insert_node = std::make_unique<InsertNode>();

        this->ExpectValue("INSERT");
        this->ExpectValue("INTO");

        auto table = this->ExpectType(TokenType::Literal);
        insert_node->SetTableName(table.value);

        this->ExpectType(TokenType::OpenParentheses);

        do
        {
            auto column = this->ExpectType(TokenType::Literal);
            insert_node->AddColumn(column.value);

            if (m_CurrentToken.type != TokenType::Comma)
            {
                break;
            }

            this->Advance();
        }
        while (true);

        this->ExpectType(TokenType::ClosedParentheses);

        this->ExpectValue("VALUES");
        this->ExpectType(TokenType::OpenParentheses);

        do
        {
            auto column = this->ExpectType(TokenType::Literal);
            insert_node->AddValue(column.value);

            if (m_CurrentToken.type != TokenType::Comma)
            {
                break;
            }

            this->Advance();
        }
        while (true);

        this->ExpectType(TokenType::ClosedParentheses);

        m_Root = std::move(insert_node);
    }

    void Ast::Advance()
    {
        while (m_Lexer->Next())
        {
            m_CurrentToken = m_Lexer->GetToken();
            if (m_CurrentToken.type != TokenType::Space)
            {
                return;
            }
        }
    }

    void Ast::ExpectValue(const std::string& value)
    {
        if (m_CurrentToken.value != value)
        {
            throw std::runtime_error("Expected '" + value + "', got '" + m_CurrentToken.value + "'");
        }

        this->Advance();
    }

    Token Ast::ExpectType(const TokenType& type)
    {
        if (m_CurrentToken.type != type)
        {
            throw std::runtime_error("Expected token type '" + std::to_string(static_cast<int>(type)));
        }

        Token token = m_CurrentToken;
        this->Advance();
        return token;
    }

    std::string Ast::ToString() const
    {
        return m_Root->ToString();
    }
}
