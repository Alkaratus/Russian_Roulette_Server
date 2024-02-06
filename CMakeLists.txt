# Copyright 2018 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# cmake build file for C++ route_guide example.
# Assumes protobuf and gRPC have been installed using cmake.
# See cmake_externalproject/CMakeLists.txt for all-in-one cmake build
# that automatically builds all the dependencies before building route_guide.

cmake_minimum_required(VERSION 3.8)

project(Russian_Roulette_Server C CXX)

include(common.cmake)

# Protos files
get_filename_component(rg_proto "protos/services.proto" ABSOLUTE)
get_filename_component(rg_proto_path "${rg_proto}" PATH)

get_filename_component(rg_listener "protos/ClientListener.proto" ABSOLUTE)
get_filename_component(rg_listener_path "${rg_listener}" PATH)

get_filename_component(rg_in_game "protos/InGameServer.proto" ABSOLUTE)
get_filename_component(rg_in_game_path "${rg_in_game}" PATH)

# Generated sources
set(rg_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/services.pb.cc")
set(rg_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/services.pb.h")
set(rg_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/services.grpc.pb.cc")
set(rg_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/services.grpc.pb.h")

set(rg_listener_srcs "${CMAKE_CURRENT_BINARY_DIR}/ClientListener.pb.cc")
set(rg_listener_hdrs "${CMAKE_CURRENT_BINARY_DIR}/ClientListener.pb.h")
set(rg_list_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/ClientListener.grpc.pb.cc")
set(rg_list_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/ClientListener.grpc.pb.h")

set(rg_in_game_srcs "${CMAKE_CURRENT_BINARY_DIR}/InGameServer.pb.cc")
set(rg_in_game_hdrs "${CMAKE_CURRENT_BINARY_DIR}/InGameServer.pb.h")
set(rg_in_game_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/InGameServer.grpc.pb.cc")
set(rg_in_game_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/InGameServer.grpc.pb.h")

add_custom_command(
      OUTPUT "${rg_proto_srcs}" "${rg_proto_hdrs}" "${rg_grpc_srcs}" "${rg_grpc_hdrs}"
        "${rg_listener_srcs}" "${rg_listener_hdrs}" "${rg_list_grpc_srcs}" "${rg_list_grpc_hdrs}"
        "${rg_in_game_srcs}" "${rg_in_game_hdrs}" "${rg_in_game_grpc_srcs}" "${rg_in_game_grpc_hdrs}"

      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${rg_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${rg_proto}" "${rg_listener}" "${rg_in_game}"
      DEPENDS "${rg_proto}" "${rg_listener}" "${rg_in_game}"
)

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_library(rg_grpc_proto
        ${rg_grpc_srcs}
        ${rg_grpc_hdrs}
        ${rg_proto_srcs}
        ${rg_proto_hdrs}
)

add_Library(listener
        ${rg_listener_srcs}
        ${rg_listener_hdrs}
        ${rg_list_grpc_srcs}
        ${rg_list_grpc_hdrs}
)

add_library(in_game_server
        ${rg_in_game_srcs}
        ${rg_in_game_hdrs}
        ${rg_in_game_grpc_srcs}
        ${rg_in_game_grpc_hdrs}
)

target_link_libraries(rg_grpc_proto PUBLIC
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
)

target_link_libraries(listener PUBLIC
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
)

target_link_libraries(in_game_server PUBLIC
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
)

target_include_directories(rg_grpc_proto PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(listener PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(in_game_server PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(Utilities)
add_subdirectory(Game_Params)
add_subdirectory(Choice_Question_Visitor)
add_subdirectory(Answers_Extractor)
add_subdirectory(Messenger)
add_subdirectory(main)
add_subdirectory(Service)
add_subdirectory(Pre_Game_Lobby)
add_subdirectory(Pre_Game_Player)
add_subdirectory(In_Game_Lobby)
add_subdirectory(In_Game_Player)
add_subdirectory(Questions)
add_subdirectory(Question_Provider)
add_subdirectory(Hard_Coded_Question_Provider)

add_subdirectory(Tests)