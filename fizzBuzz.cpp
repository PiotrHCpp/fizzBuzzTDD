#include "gtest/gtest.h"
#include <string>

struct TestContainer {
    TestContainer(unsigned argument, std::string expected) :
        argument(argument), expected(expected)
    {}

    unsigned argument;
    std::string expected;
};

struct FizzBuzzTests : public ::testing::TestWithParam<TestContainer> {
};

INSTANTIATE_TEST_CASE_P(ParamTest,
                        FizzBuzzTests,
                        ::testing::Values(
                            TestContainer{0, "0"},
                            TestContainer{1, "1"},
                            TestContainer{2, "2"},
                            TestContainer{3, "Fizz"},
                            TestContainer{5, "Buzz"},
                            TestContainer{6, "Fizz"},
                            TestContainer{10, "Buzz"},
                            TestContainer{12, "Fizz"},
                            TestContainer{15, "FizzBuzz"},
                            TestContainer{30, "FizzBuzz"},
                            TestContainer{100, "Buzz"}
                        )
);

std::string fizzBuzz(unsigned value) {
    if(100 < value) {
        throw std::out_of_range("argument is out of range (>100)");
    }
    if(0 == value) {
        return "0";
    }
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
    unsigned argument = 1;
    ASSERT_NO_THROW(fizzBuzz(argument));
    std::string result = fizzBuzz(argument);
}

TEST_P(FizzBuzzTests, checkExpectedValuesForFizzBuzz) {
    unsigned argument = GetParam().argument;
    std::string expected = GetParam().expected;
    ASSERT_NO_THROW(fizzBuzz(argument));
    EXPECT_EQ(expected, fizzBuzz(argument));
}

TEST(FizzBuzzTests, throwExceptionIfArgumentGreaterThan100) {
    const unsigned argument = 101;
    ASSERT_ANY_THROW(fizzBuzz(argument));
    ASSERT_THROW(fizzBuzz(argument), std::out_of_range);
}
