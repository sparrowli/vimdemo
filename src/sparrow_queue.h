#ifndef _SPARROW_QUEUE_H_
#define _SPARROW_QUEUE_H_

#include <stddef.h>

template <typename E>
class SparrowQueue;

template <typename E>
class SparrowQueueNode {
	friend class SparrowQueue<E>;

public:
	const E& element() const { return element_; }

	SparrowQueueNode* next() { return next_; }

	const SparrowQueueNode* next() const { return next_; }

private:
	explicit SparrowQueueNode(const E& an_element) : element_(an_element), next_(NULL) {}

	const SparrowQueueNode& operator = (const SparrowQueueNode&);

	E element_;
	SparrowQueueNode* next_;
}; 

template <typename E>
class SparrowQueue {
public:
	SparrowQueue() : head_(NULL), last_(NULL), size_(0) {}

	~SparrowQueue() { Clear(); }

	void Clear() {
		if (size_ > 0) {

			SparrowQueueNode<E>* node = head_;
			SparrowQueueNode<E>* next = node->next();
			for (; ;) {
				delete node;
				node = next;
				if (node == NULL) break;
				next = node->next();
			}

			head_ = last_ = NULL;
			size_ = 0;
		}
	}
			   
	size_t Size() const { return size_; }

	SparrowQueueNode<E>* Head() { return head_; }
	const SparrowQueueNode<E>* Head() const { return head_; }

	SparrowQueueNode<E>* Last() { return last_; }
	const SparrowQueueNode<E>* Last() const { return last_; }
	
	void Enqueue(const E& element) {
		SparrowQueueNode<E>* new_node = new SparrowQueueNode<E>(element);

		if (size_ == 0) {
			head_ = last_ = new_node;
			size_ = 1;
		} else {
			last_->next_ = new_node;
			last_ = new_node;
			size_++;
		}
	}

	E* Dequeue() {
		if (size_ == 0) {
			return NULL;
		}

		const SparrowQueueNode<E>* const old_head = head_;
		head_ = head_->next_;
		size_--;
		if (size_ == 0) {
			last_ = NULL;
		}

		E* element = new E(old_head->element());
		delete old_head;

		return element;
	}

	template <typename F>
	SparrowQueue* Map(F function) const {
		SparrowQueue* new_queue = new SparrowQueue();
		for (const SparrowQueueNode<E>* node = head_; node != NULL; node = node->next_) {
			new_queue->Enqueue(function(node->element()));
		}

		return new_queue;
	}

	private:
		SparrowQueueNode<E>* head_;		
		SparrowQueueNode<E>* last_;		
		size_t size_;

		SparrowQueue(const SparrowQueue&);
		const SparrowQueue& operator = (const SparrowQueue&);
};

#endif // _SPARROW_QUEUE_H_
