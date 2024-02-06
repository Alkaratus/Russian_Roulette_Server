cmake_minimum_required(VERSION 3.8)

set(_target In_Game_Lobby)
add_library(${_target} "In_Game_Lobby.h" "In_Game_Lobby.cpp" "In_Game_Server.h" "In_Game_Server.cpp"
        Round_Manager.cpp
        Round_Manager.h)

target_link_libraries(${_target} PUBLIC Messenger Pre_Game_Lobby In_Game_Player in_game_server Hard_Coded_Question_Provider)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})