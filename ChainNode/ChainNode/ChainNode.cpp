// ChainNode.cpp: 定義應用程式的進入點。
//
#include "ChainNode.h"
#include <iostream>

template <typename T>
void Chain<T>::InsertBack(const T& item) {
	if (first) {  // nonempty
		last->link = new ChainNode<T>(item);
		last = last->link;
	}
	else {
		first = last = new ChainNode<T>(item);
	}
}

template <typename T>
void Chain<T>::Concatenate(Chain<T>& c) {
	if (first) {  // this 是否為nonempty
		last->link = c.first;
		last = c.last;
	}
	else {
		first = c.first;
		last = c.last;
	}
	c.first = c.last = nullptr;  // empty c
}

/* 反轉鏈結串列
 1. 使用三個指標：current、previous、r
 2. current:指向當前節點位置、previous:指向current前一個節點位置、
 r:存放previous的位置，因為previous會被current覆蓋掉，所以需要一個暫存變數r來保存previous的位置
 r、p、c
 */
template <typename T>
void Chain<T>::Reverse() {
	ChainNode<T> *current = first, *previous = nullptr;
	last = first;  // 反轉後的最後一個節點是原來的第一個節點
	while (current) {
		ChainNode<T> *r = previous;
		previous = current;
		current = current->link;
		previous->link = r;
	}
	first = previous;
}

template <typename T>
void Chain<T>::Print() const {
	for (ChainNode<T>* current = first; current; current = current->link) {
		std::cout << current->data << std::endl;
	}
}

int main() {
	Chain<int> c;
	c.InsertBack(1);
	c.InsertBack(2);
	c.InsertBack(3);
	c.Reverse();
	c.Print();
	return 0;
}