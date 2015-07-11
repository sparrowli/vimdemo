#include "gtest/gtest.h"
#include "math_utilities.h"

class MathUtilitiesTest : public testing::Test {
protected:
	virtual void SetUp() {
}

	MathUtilities m_;
};

TEST_F(MathUtilitiesTest, WhenNegativeReturnOne) {
	EXPECT_EQ(1, m_.Factorial(-5));
}

TEST_F(MathUtilitiesTest, WhenZeroReturnOne) {
	EXPECT_EQ(1, m_.Factorial(0));
}

TEST_F(MathUtilitiesTest, WhenPositiveReturnExpected) {
	EXPECT_EQ(40320, m_.Factorial(8));
}
