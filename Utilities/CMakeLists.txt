set(_target Utilities)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Pre_Game_Player)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})