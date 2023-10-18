#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

struct TokenType
{
    std::string mName;
    std::string mRegex;
};

const TokenType TOKEN_NUMBER = {std::string("NUMBER"), std::string("[0-9]*")};
const TokenType TOKEN_VARIABLE = {std::string("VARIABLE"), std::string("[a-zA-Z]*")};
const TokenType TOKEN_SEMICOLON = {std::string("SEMICOLON"), std::string(";")};
const TokenType TOKEN_SPACE = {std::string("SPACE"), std::string("[ \n\t\r]")};
const TokenType TOKEN_ASIGN = {std::string("ASSIGN"), std::string("=")};
const TokenType TOKEN_LEFT_BRACKET = {std::string("LEFT_BRACKET"), std::string("\\(")};
const TokenType TOKEN_RIGHT_BRACKET = {std::string("RIGHT_BRACKET"), std::string("\\)")};
const TokenType TOKEN_PLUS = {std::string("PLUS"), std::string("\\+")};
const TokenType TOKEN_MINUS = {std::string("PLUS"), std::string("\\-")};

std::vector<const TokenType *> TOKEN_TYPES = {
    &TOKEN_NUMBER, &TOKEN_VARIABLE,     &TOKEN_SEMICOLON,     &TOKEN_SPACE,
    &TOKEN_ASIGN,  &TOKEN_LEFT_BRACKET, &TOKEN_RIGHT_BRACKET, &TOKEN_PLUS};

class Token
{
  public:
    Token(const TokenType *type, std::string text, uint32_t pos)
        : mType(type), mData(text), mPosition(pos)
    {
    }

  public:
    const TokenType *mType;
    std::string mData;
    uint32_t mPosition;
};

class Lexer
{
  public:
    Lexer(std::string code) : mCode(code) { printf("Code: '%s'\n", code.c_str()); }

    std::vector<Token> LexAnalysis()
    {
        while (NextToken())
        {
            printf("Next token readen\n");
        }

        std::vector<Token> filteredTokenList;
        std::copy_if(mTokenList.begin(), mTokenList.end(), std::back_inserter(filteredTokenList),
                     [](const Token &token) -> bool {
                        return token.mType != &TOKEN_SPACE;
                     });
        mTokenList = filteredTokenList;         

        return mTokenList;
    }

  private:
    bool NextToken()
    {
        if (mPos >= mCode.length())
        {
            return false;
        }

        for (auto tokenType : TOKEN_TYPES)
        {
            const std::regex tokenRegEx = std::regex("^" + tokenType->mRegex);
            std::smatch matches;
            std::string curCode = mCode.substr(mPos);
            bool matchResult = std::regex_search(curCode, matches, tokenRegEx);
            if (matchResult && !matches[0].str().empty())
            {
                Token token(tokenType, matches[0].str(), mPos);
                mTokenList.push_back(std::move(token));
                mPos += matches[0].str().size();

                printf("Token type is '%s'\n", tokenType->mName.c_str());

                return true;
            }
        }

        throw std::exception();
    }

  private:
    std::string mCode;
    int mPos = 0;
    std::vector<Token> mTokenList;
};

int main()
{
    std::ifstream inputFile("../../sources/script.slang");
    std::stringstream bufferCode;
    bufferCode << inputFile.rdbuf();

    Lexer lex(bufferCode.str());
    auto res = lex.LexAnalysis();
}