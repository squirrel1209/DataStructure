#pragma once

template <typename T>
class Stack {
public:
	Stack(int stackCapacity = 10);
	~Stack();
	bool IsEmpty() const;
	T& Top();
	void push(const T& item);
	void pop();

private:
	T* stack;
	int top;
	int capacity;
};