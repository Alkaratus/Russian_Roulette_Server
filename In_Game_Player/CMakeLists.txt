cmake_minimum_required(VERSION 3.8)

set(_target In_Game_Player)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Answers_Extractor Pre_Game_Player Hard_Coded_Question_Provider)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})