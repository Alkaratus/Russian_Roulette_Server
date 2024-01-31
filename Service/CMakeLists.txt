set(_target MainServer)

add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC
        rg_grpc_proto In_Game_Lobby Messenger
)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})