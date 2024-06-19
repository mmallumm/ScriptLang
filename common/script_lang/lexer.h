#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <regex>

#include "token.h"

namespace sl
{
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
                     [](const Token &token) -> bool { return token.mType.mName != "SPACE"; });
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

        for (auto tokenType : GetTokenTypeDict())
        {
            const std::regex tokenRegEx = std::regex("^" + std::string(tokenType.second));
            std::smatch matches;
            std::string curCode = mCode.substr(mPos);
            bool matchResult = std::regex_search(curCode, matches, tokenRegEx);
            if (matchResult && !matches[0].str().empty())
            {
                Token token{TokenType{tokenType.first, tokenType.second}, matches[0].str(), mPos};
                mTokenList.push_back(std::move(token));
                mPos += matches[0].str().size();

                printf("Token type is '%s'\n", tokenType.first);

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
} // namespace sl

#endif