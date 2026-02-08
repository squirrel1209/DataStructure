#pragma once

template <typename T>
class Queue {
public:
	Queue(int queueCapacity = 10);
	~Queue();
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();
private:
	T *queue;
	int front;
	int rear;
	int capacity;
};
