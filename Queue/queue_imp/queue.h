#pragma once
class queue
{
private:
	int* arr;
	int capacity;
	int size;
	int front;
	int back;
public:
	queue(int cap);
	~queue();

	void Enqueue(int data);
	void Dequeue();
	int Front() const;
	int Back() const;
	bool IsFull()const;
	bool IsEmpty()const;
};

