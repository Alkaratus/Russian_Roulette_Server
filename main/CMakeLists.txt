cmake_minimum_required(VERSION 3.8)

# Targets route_guide_(server)
set(_target main)
add_executable(${_target} "${_target}.cpp")

target_link_libraries(${_target} rg_grpc_proto listener MainServer ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})