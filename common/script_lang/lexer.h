#ifndef LEXER_H
#define LEXER_H

#include <iostream>
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
    std::vector<Token> LexAnalysis(std::string code) const;
    Token NextToken(const std::string& code, uint32_t& pos) const;
};
} // namespace sl

#endif