//
// Created by alkaratus on 31.01.24.
//

#include <catch2/catch_test_macros.hpp>
#include "Test.h"

Test test;

TEST_CASE("Unique generator exception throw"){
    REQUIRE_THROWS(generate_random_unique_list(1,5,6));
}