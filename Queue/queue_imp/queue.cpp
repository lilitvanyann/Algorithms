#include "queue.h"

	queue::queue(int cap) : capacity(cap), size(0), front(-1), back(-1) {
		arr = new int[capacity];
	}

	queue::~queue() {
		delete[]arr;
	}

	void queue::Enqueue(int data) {
		if (size == capacity)return;
		if (back == capacity - 1) return; //Prevent overflow
		if (size == 0) {
			front = 0;
		}
		back++;
		arr[back] = data;
		size++;
	}
	void queue::Dequeue() {
		if (size == 0)
			return;
		front++;
		size--;
		if (size == 0) {
			front = -1;
			back = -1;
		}
	}

	int queue::Front() const {
		if (size == 0)
			return -1;
		return arr[front];
	}

	int queue::Back() const {
		if (size == 0)
			return -1;
		return arr[back];
	}

	bool queue::IsFull()const {
		return size == capacity;
	}
	bool queue::IsEmpty()const {
		return size == 0;
	}

