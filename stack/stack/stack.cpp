// stack.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "stack.hpp"

template <typename T>
Stack<T>::Stack(int stackCapacity) : 
	capacity(stackCapacity) 
{
	stack = new T[capacity];
	top = -1;
}

template <typename T>
Stack<T>::~Stack() {
	delete[] stack;
}

template <typename T>
inline bool Stack<T>::IsEmpty() const {
	return top == -1;
}

template <typename T>
inline T& Stack<T>::Top() {
	if (IsEmpty()) {
		throw "Stack is empty. No top element.";
	}
	return stack[top];
}

template <typename T>
void Stack<T>::push(const T& item) {
	if (top == capacity - 1) {
		throw "Stack overflow. Cannot push new item.";
	}
	stack[++top] = item;
}

template <typename T>
void Stack<T>::pop() {
	if (IsEmpty()) {
		throw "Stack underflow. Cannot pop from empty stack.";
	}
	stack[top--].~T();
}
