Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

add_executable(Tests "main.cpp"
        Test.cpp
        Test.h)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Tests PUBLIC Utilities)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)
catch_discover_tests(Tests)