#include <fstream>
#include <sstream>
#include <iostream>

#include "script_lang/lexer.h"

using namespace sl;

int main()
{
    std::ifstream inputFile("sources/script.slang");
    std::stringstream bufferCode;
    bufferCode << inputFile.rdbuf();

    sl::Lexer lex;
    auto res = lex.LexAnalysis(bufferCode.str());
}