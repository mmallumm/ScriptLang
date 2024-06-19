cmake_minimum_required(VERSION 3.0)
project(ScriptLangTest)

add_subdirectory(common)

add_executable(ScriptLangTest main.cpp)
target_link_libraries(ScriptLangTest ScriptLangLib)
target_include_directories(ScriptLangTest PUBLIC ${CMAKE_CURRENT_LIST_DIR}/common)

set_property(TARGET ScriptLangTest PROPERTY CXX_STANDARD 17)