#include "gtest/gtest.h"
#include <string>

std::string fizzBuzz(unsigned value) {
    if(3 == value) {
        return "Fizz";
    }
    if(5 == value) {
        return "Buzz";
    }
    return std::to_string(value);
}

TEST(FizzBuzzTests, canCallFizzBuzz) {
    std::string result = fizzBuzz(1);
}

TEST(FizzBuzzTests, returns1With1PassedIn) {
    EXPECT_EQ("1", fizzBuzz(1));
}

TEST(FizzBuzzTests, returns2With2PassedIn) {
    EXPECT_EQ("2", fizzBuzz(2));
}

TEST(FizzBuzzTests, returnsFizzWith3PassedIn) {
    EXPECT_EQ("Fizz", fizzBuzz(3));
}

TEST(FizzBuzzTests, returnsBuzzWith5PassedIn) {
    EXPECT_EQ("Buzz", fizzBuzz(5));
}
