#include "gtest/gtest.h"
#include <string>

std::string fizzBuzz(unsigned value) {
    const bool valueIsMultipleOf3 = (0 == (value % 3));
    const bool valueIsMultipleOf5 = (0 == (value % 5));
    if(valueIsMultipleOf3 && valueIsMultipleOf5) {
        return "FizzBuzz";
    }
    if(valueIsMultipleOf3) {
        return "Fizz";
    }
    if(valueIsMultipleOf5) {
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

TEST(FizzBuzzTests, returnsFizzBuzzWith15PassedIn) {
    EXPECT_EQ("FizzBuzz", fizzBuzz(15));
}
