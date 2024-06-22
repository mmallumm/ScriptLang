#include "lexer.h"

#include <cassert>

using namespace sl;

std::vector<Token> Lexer::LexAnalysis(std::string code) const
{
    printf("Code: '%s'\n", code.c_str());

    uint32_t pos = 0;
    std::vector<Token> tokenList;

    while (true)
    {
        auto token = NextToken(code, pos);
        if(!token.mType.IsValid()) {
            break;
        }
        
        printf("Next token readen, type: '%s', data: '%s'\n", token.mType.mName, token.mData.c_str());
        tokenList.push_back(std::move(token));
    }

    std::vector<Token> filteredTokenList;
    std::copy_if(tokenList.begin(), tokenList.end(), std::back_inserter(filteredTokenList),
                 [](const Token &token) -> bool { return token.mType.mName != "SPACE"; });
    tokenList = filteredTokenList;

    return tokenList;
}

Token Lexer::NextToken(const std::string &code, uint32_t &pos) const
{
    if (pos >= code.length())
    {
        return Token{};
    }

    for (auto tokenType : GetTokenTypeDict())
    {
        const std::regex tokenRegEx = std::regex("^" + std::string(tokenType.second));
        std::smatch matches;
        std::string curCode = code.substr(pos);
        bool matchResult = std::regex_search(curCode, matches, tokenRegEx);
        if (matchResult && !matches[0].str().empty())
        {
            pos += matches[0].str().size();
            return Token{TokenType{tokenType.first, tokenType.second}, matches[0].str(), pos};
        }
    }

    assert(false && "No token matched");
}