// Bag.h: 標準系統 include 檔案的 include 檔案，
// 或專案專屬的 Include 檔案。

#pragma once

#include <iostream>
class Bag {
public:
	Bag(int bagCapacity = 10);
	virtual ~Bag();
	virtual int Size() const;
	virtual bool IsEmpty() const;
	virtual int Element() const;
	virtual void Push(const int);
	virtual void Pop();
protected:
	int* array;
	int capacity;
	int top;
};

class Stack : public Bag {
public:
    Stack(int stackCapacity = 10);
	~Stack();
	int Top() const;
	void Pop();
};
