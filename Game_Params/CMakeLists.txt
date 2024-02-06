set(_target Game_Params)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})