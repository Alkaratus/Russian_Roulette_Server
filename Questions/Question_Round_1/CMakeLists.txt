set(_target Question_Round_1)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Choice_Question Choice_Question_Visitor)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})