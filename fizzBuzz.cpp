#include "gtest/gtest.h"
#include <string>

bool isMultiple(unsigned value, unsigned base) {
    return (0 == (value % base));
}

std::string fizzBuzz(unsigned value) {
    if(isMultiple(value, 3)) {
        return "Fizz";
    }
    if(isMultiple(value, 5)) {
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

TEST(FizzBuzzTests, returnsFizzWith6PassedIn) {
    EXPECT_EQ("Fizz", fizzBuzz(6));
}

TEST(FizzBuzzTests, returnsBuzzWith10PassedIn) {
    EXPECT_EQ("Buzz", fizzBuzz(10));
}
