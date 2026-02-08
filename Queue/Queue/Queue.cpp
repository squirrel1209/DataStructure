// Queue.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。

#include "Queue.hpp"

template <typename T>
Queue<T>::Queue(int queueCapacity)
	: capacity(queueCapacity), front(0), rear(0)
{
	queue = new T[capacity];
}

template <typename T>
inline Queue<T>::~Queue()
{
	delete[] queue;
}

template <typename T>
inline bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template <typename T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty())
		throw "Queue is empty. No front element.";
	return queue[(front + 1) % capacity];
}

template <typename T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty())
		throw "Queue is empty. No rear element.";
	return queue[rear];
}

template <typename T>
inline void Queue<T>::Push(const T& item)
{
	if ((rear + 1) % capacity == front)
		throw "Queue is full. Cannot add new element.";
	rear = (rear + 1) % capacity;
	queue[rear] = item; 
}

template <typename T>
inline void Queue<T>::Pop()
{
	if (IsEmpty())
		throw "Queue is empty. Cannot remove element.";
	front = (front + 1) % capacity;
	queue[front].~T();
}

