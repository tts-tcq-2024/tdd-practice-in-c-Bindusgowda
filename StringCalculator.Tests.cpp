#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ReturnsZeroForEmptyInput{
    int expectedresult = 0;
    const char* input = " ";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ReturnsZeroForSingleZeroInput{
    int expectedresult = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ReturnsSumOfInputNumbersSeparatedByCommas{
    int expectedresult = 3;
    const char*  input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ReturnsSumOfInputNumbersSeparatedByNewLines) {
    int expectedresult = 3;
    const char*  input = "1\n2";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ReturnsZeroIfInputStringDoesNotHaveNumbers{
    int expectedresult = 0;
    const char* input = "Hello, world!";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoresInputCharactersThatAreNeitherNumbersNorDelimiters) {
    int expectedresult = 22;
    const char*  input = "1, 2*1";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThanThousand) {
    int expectedresult = 1;
    const char*  input = "1,1001";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}
