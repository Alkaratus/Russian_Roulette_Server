set(_target Question_Round_2)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Question_Round_1)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})