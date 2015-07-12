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
	EXPECT_GT(m_.Factorial(-8), 0);
}

TEST_F(MathUtilitiesTest, WhenZeroReturnOne) {
	EXPECT_EQ(1, m_.Factorial(0));
}

TEST_F(MathUtilitiesTest, WhenPositiveReturnExpected) {
	EXPECT_EQ(40320, m_.Factorial(8));
}

TEST_F(MathUtilitiesTest, IsPrimeWhenNegative) {
	EXPECT_FALSE(m_.IsPrime(-1));
	EXPECT_FALSE(m_.IsPrime(INT_MIN));
}

TEST_F(MathUtilitiesTest, IsPrimeWhenSomeTrivial) {
	EXPECT_FALSE(m_.IsPrime(0));
	EXPECT_FALSE(m_.IsPrime(1));
	EXPECT_TRUE(m_.IsPrime(2));
	EXPECT_TRUE(m_.IsPrime(3));
}

TEST_F(MathUtilitiesTest, IsPrimeWhenPositive) {
	EXPECT_FALSE(m_.IsPrime(4));
	EXPECT_TRUE(m_.IsPrime(5));
	EXPECT_FALSE(m_.IsPrime(6));
	EXPECT_FALSE(m_.IsPrime(39));
}
