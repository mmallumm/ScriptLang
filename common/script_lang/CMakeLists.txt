project(ScriptLang)

set(HeaderFiles token.h lexer.h)
set(SourceFiles src/token.cpp src/lexer.cpp)
add_library(ScriptLangLib ${SourceFiles} ${HeaderFiles} ${SourceFiles})

target_include_directories(ScriptLangLib PRIVATE ${CMAKE_CURRENT_LIST_DIR})