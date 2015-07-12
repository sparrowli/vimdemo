#include "sparrow_string.h"
#include "gtest/gtest.h"

TEST(SparrowString, DefaultConstructor) {
	const SparrowString ss;

	EXPECT_STREQ(NULL, ss.c_string());

	EXPECT_EQ(0u, ss.Length());
}

const char kHelloString[] = "Hello, world!";

TEST(SparrowString, ConstructorFromString) {
	const SparrowString ss(kHelloString);

	EXPECT_EQ(0, strcmp(ss.c_string(), kHelloString));
	EXPECT_EQ(sizeof(kHelloString)/sizeof(kHelloString[0]) - 1,
			  ss.Length());
}

TEST(SparrowString, CopyConstructor) {
	const SparrowString ss1(kHelloString);
	const SparrowString ss2 = ss1;

	EXPECT_EQ(0, strcmp(ss2.c_string(), kHelloString));
}

TEST(SparrowString, Set) {
	SparrowString ss;

	ss.Set(kHelloString);
	EXPECT_EQ(0, strcmp(ss.c_string(), kHelloString));

	ss.Set(ss.c_string());
	EXPECT_EQ(0, strcmp(ss.c_string(), kHelloString));

	ss.Set(NULL);
	EXPECT_STREQ(NULL, ss.c_string());
}
