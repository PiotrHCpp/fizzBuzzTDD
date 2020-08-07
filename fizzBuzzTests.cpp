#include "gtest/gtest.h"
#include "fizzBuzz.hpp"

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

TEST_P(FizzBuzzTests, checkExpectedValuesForFizzBuzz) {
    unsigned argument = GetParam().argument;
    std::string expected = GetParam().expected;
    EXPECT_EQ(expected, fizzBuzz(argument));
}

TEST(FizzBuzzTests, throwExceptionIfArgumentGreaterThan100) {
    const unsigned argument = 101;
    ASSERT_THROW(fizzBuzz(argument), std::out_of_range);
}
