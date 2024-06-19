#include "token.h"

namespace
{
sl::TokenTypeDict tokenTypeTable = {
    {"VAR", "[a-zA-Z]*"},     {"NUM", "[0-9]*"}, {"SEMICOLON", ";"},
    {"SPACE", "[ \n\t\r]"},   {"ASSIGN", "="},   {"LEFT_BRACKET", "\\("},
    {"RIGHT_BRACKET", "\\)"}, {"PLUS", "\\+"},   {"MINUS", "\\-"}};

};

const sl::TokenTypeDict &sl::GetTokenTypeDict() { return tokenTypeTable; }