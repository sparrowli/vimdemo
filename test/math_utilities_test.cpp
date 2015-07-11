#include "gtest/gtest.h"
#include "math_utilities.h"

class MathUtilitiesTest : public testing::Test {
protected:
	virtual void SetUp() {
}

	MathUtilities m_;
};

TEST_F(MathUtilitiesTest, InitializesCorrectly) {
	EXPECT_TRUE(m_.StatusIsOK());
}
