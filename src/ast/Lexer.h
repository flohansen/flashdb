#pragma once

#include <string>

namespace flashdb
{
    enum TokenType
    {
        Literal,
        Space,
        Comma,
        OpenParentheses,
        ClosedParentheses,
        SingleQuote,
        Unknown,
    };

    struct Token
    {
        TokenType type;
        std::string value;
    };

    class Lexer
    {
    private:
        std::string m_Input;
        size_t m_Idx;
        Token m_Token;
    public:
        Lexer(std::string input);
    public:
        bool Next();
        Token GetToken() const;
    private:
        void ScanLiteral();
        void ScanSpace();
        void ScanComma();
        void ScanOpenParentheses();
        void ScanClosedParentheses();
        void ScanSingleQuote();
    };
}
