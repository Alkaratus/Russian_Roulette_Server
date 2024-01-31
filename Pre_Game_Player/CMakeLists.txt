set(_target Pre_Game_Player)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC
        listener
        ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})