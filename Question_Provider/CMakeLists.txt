set(_target Question_Provider)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Question_Round_4 Question_Round_5 Utilities Game_Params)
target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})