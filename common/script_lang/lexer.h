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
    Lexer(std::string code);

    std::vector<Token> LexAnalysis();

  private:
    bool NextToken();

  private:
    std::string mCode;
    int mPos = 0;
    std::vector<Token> mTokenList;
};
} // namespace sl

#endif