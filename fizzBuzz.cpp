#include "gtest/gtest.h"
#include <string>

struct TestingValues {
    TestingValues(unsigned argument, std::string expected) :
        argument(argument), expected(expected)
    {}

    unsigned argument;
    std::string expected;
};

struct FizzBuzzTests : public ::testing::TestWithParam<TestingValues> {
};

INSTANTIATE_TEST_CASE_P(ParamTest,
                        FizzBuzzTests,
                        ::testing::Values(
                            TestingValues{0, "0"},
                            TestingValues{1, "1"},
                            TestingValues{2, "2"},
                            TestingValues{3, "Fizz"},
                            TestingValues{5, "Buzz"},
                            TestingValues{6, "Fizz"},
                            TestingValues{10, "Buzz"},
                            TestingValues{12, "Fizz"},
                            TestingValues{15, "FizzBuzz"},
                            TestingValues{30, "FizzBuzz"},
                            TestingValues{100, "Buzz"}
                        )
);

std::string fizzBuzz(unsigned argument) {
    if(100 < argument) {
        throw std::out_of_range("argument is out of range (>100)");
    }
    if(0 == argument) {
        return "0";
    }
    const bool valueIsMultipleOf3 = (0 == (argument % 3));
    const bool valueIsMultipleOf5 = (0 == (argument % 5));
    if(valueIsMultipleOf3 && valueIsMultipleOf5) {
        return "FizzBuzz";
    }
    if(valueIsMultipleOf3) {
        return "Fizz";
    }
    if(valueIsMultipleOf5) {
        return "Buzz";
    }
    return std::to_string(argument);
}

TEST_P(FizzBuzzTests, checkExpectedValuesForFizzBuzz) {
    unsigned argument = GetParam().argument;
    std::string expected = GetParam().expected;
    EXPECT_EQ(expected, fizzBuzz(argument));
}

TEST(FizzBuzzTests, throwExceptionIfArgumentGreaterThan100) {
    const unsigned argument = 101;
    ASSERT_THROW(fizzBuzz(argument), std::out_of_range);
}
