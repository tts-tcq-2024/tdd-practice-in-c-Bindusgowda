#include <gtest/gtest.h>
#include "string.h"
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ReturnsZeroForEmptyInput) {
    ASSERT_EQ(calculateStringSum(""),0);
}

TEST(StringCalculatorAddTests, ReturnsZeroForSingleZeroInput) {
    ASSERT_EQ(calculateStringSum("0"),0);
}

TEST(StringCalculatorAddTests, ReturnsSumOfInputNumbersSeparatedByCommas) {
    ASSERT_EQ(calculateStringSum("1,2"),3);
}

TEST(StringCalculatorAddTests, ReturnsSumOfInputNumbersSeparatedByNewLines) {
    ASSERT_EQ(calculateStringSum("1\n2"),3);
}

TEST(StringCalculatorAddTests, ReturnsZeroIfInputStringDoesNotHaveNumbers) {
    ASSERT_EQ(calculateStringSum(",\n,"),0);
    ASSERT_EQ(calculateStringSum("Hello, world!"),0);
}

TEST(StringCalculatorAddTests, ThrowsExceptionForNegativeInputNumbers) {
    ASSERT_ANY_THROW(calculateStringSum("-1,1,-1"));

    try{
        calculateStringSum("-1,1,-1");
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ(e.what(),"negative numbers not allowed: -1,-1");
    }
}
