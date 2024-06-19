#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_map>

namespace sl
{
using TokenTypeDict = std::unordered_map<const char *, const char *>;
const TokenTypeDict &GetTokenTypeDict();

struct TokenType
{
    const char *mName = nullptr;
    const char *mmRegex = nullptr;
};

struct Token
{
    TokenType mType;
    std::string mData;
    uint32_t mPosition;
};
} // namespace sl

#endif