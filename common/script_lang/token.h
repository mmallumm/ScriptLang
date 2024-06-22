#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_map>

namespace sl
{
using TokenTypeDict = std::unordered_map<const char *, const char *>;
const TokenTypeDict &GetTokenTypeDict();

class TokenType
{
  public:
    bool IsValid() const;

  public:
    const char *mName = nullptr;
    const char *mRegex = nullptr;
};

struct Token
{
    TokenType mType;
    std::string mData;
    uint32_t mPosition = 0;
};
} // namespace sl

inline bool operator==(const sl::TokenType &left, const sl::TokenType &rigth)
{
    return std::strcmp(left.mName, rigth.mName) == 0;
}

#endif