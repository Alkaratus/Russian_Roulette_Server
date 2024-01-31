cmake_minimum_required(VERSION 3.8)

set(_target Pre_Game_Lobby)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Pre_Game_Player)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})