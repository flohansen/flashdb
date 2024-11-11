#include "Lexer.h"
#include <cctype>

namespace flashdb
{
    Lexer::Lexer(std::string input)
        : m_Input(input), m_Idx(0)
    {
    }

    bool Lexer::Next()
    {
        if (m_Idx >= m_Input.length())
        {
            return false;
        }

        char c = m_Input[m_Idx];

        if (isalnum(c))
        {
            this->ScanLiteral();
            return true;
        }
        if (isspace(c))
        {
            this->ScanSpace();
            return true;
        }
        if (c == ',')
        {
            this->ScanComma();
            return true;
        }
        if (c == '(')
        {
            this->ScanOpenParentheses();
            return true;
        }
        if (c == ')')
        {
            this->ScanClosedParentheses();
            return true;
        }
        if (c == '\'')
        {
            this->ScanSingleQuote();
            return true;
        }

        return false;
    }

    Token Lexer::GetToken() const
    {
        return m_Token;
    }

    void Lexer::ScanLiteral()
    {
        std::string value;

        while (char c = m_Input[m_Idx])
        {
            if (!isalnum(c))
            {
                break;
            }

            value += c;
            m_Idx++;
        }

        m_Token.type = TokenType::Literal;
        m_Token.value = value;
    }

    void Lexer::ScanSpace()
    {
        m_Token.type = TokenType::Space;
        m_Token.value = m_Input[m_Idx];
        m_Idx++;
    }

    void Lexer::ScanComma()
    {
        m_Token.type = TokenType::Comma;
        m_Token.value = m_Input[m_Idx];
        m_Idx++;
    }

    void Lexer::ScanOpenParentheses()
    {
        m_Token.type = TokenType::OpenParentheses;
        m_Token.value = m_Input[m_Idx];
        m_Idx++;
    }

    void Lexer::ScanClosedParentheses()
    {
        m_Token.type = TokenType::ClosedParentheses;
        m_Token.value = m_Input[m_Idx];
        m_Idx++;
    }

    void Lexer::ScanSingleQuote()
    {
        m_Token.type = TokenType::SingleQuote;
        m_Token.value = m_Input[m_Idx];
        m_Idx++;
    }
}
