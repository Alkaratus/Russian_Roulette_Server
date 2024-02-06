set(_target Hard_Coded_Question_Provider)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Question_Provider)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})