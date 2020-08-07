#include "gtest/gtest.h"
#include <string>

std::string fizzBuzz(unsigned value) {
    return "1";
}

TEST(FizzBuzzTests, canCallFizzBuzz) {
    std::string result = fizzBuzz(1);
}

TEST(FizzBuzzTests, returns1With1PassedIn) {
    EXPECT_EQ("1", fizzBuzz(1));
}
