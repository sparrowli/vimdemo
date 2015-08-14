#include "gtest/gtest.h"
#include "sparrow_queue.h"

class SparrowQueueTest : public testing::Test {
protected:
	
	virtual void SetUp() {
		sq2_.Enqueue(1);
		sq3_.Enqueue(2);
		sq3_.Enqueue(3);
	}

	static int Double(int n) {
		return 2*n;
	}

	void MapTester(const SparrowQueue<int> * q) {

		const SparrowQueue<int> * const new_q = q->Map(Double);

		ASSERT_EQ(q->Size(), new_q->Size());

		for ( const SparrowQueueNode<int> * n1 = q->Head(), * n2 = new_q->Head();
				n1 != NULL; n1 = n1->next(), n2 = n2->next() ) {
			EXPECT_EQ(2 * n1->element(), n2->element());
		}

		delete new_q;
	}

	SparrowQueue<int> sq1_;
	SparrowQueue<int> sq2_;
	SparrowQueue<int> sq3_;
};


TEST_F(SparrowQueueTest, DefaultConstructor) {
	EXPECT_EQ(0u, sq1_.Size());
}

TEST_F(SparrowQueueTest, Dequeue) {
	int * n = sq1_.Dequeue();
	EXPECT_TRUE(n == NULL);

	n = sq2_.Dequeue();
	ASSERT_TRUE(n != NULL);
	EXPECT_EQ(1, *n);
	EXPECT_EQ(0u, sq2_.Size());
	delete n;

	n = sq3_.Dequeue();
	ASSERT_TRUE(n != NULL);
	EXPECT_EQ(2, *n);
	EXPECT_EQ(1u, sq3_.Size());
	delete n;
	sq3_.Clear();
	EXPECT_EQ(0u, sq3_.Size());
}

TEST_F(SparrowQueueTest, Map) {
	MapTester(&sq1_);
	MapTester(&sq2_);
	MapTester(&sq3_);
}
