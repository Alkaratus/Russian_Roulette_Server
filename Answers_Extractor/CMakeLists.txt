set(_target Answers_Extractor)
add_library(${_target} "${_target}.h" "${_target}.cpp")

target_link_libraries(${_target} PUBLIC Choice_Question_Visitor listener Question_Round_4)

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})