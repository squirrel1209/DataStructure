#pragma once
#include <iostream>

template <typename T> class Chain;
template <typename T> class CircularList;
template <typename T> class ChainIterator;

template <typename T>
class ChainNode {
	friend class Chain<T>;
	friend class CircularList<T>;
	friend class ChainIterator<T>;
public:
	ChainNode() : link(nullptr) {}
	ChainNode(const T& item, ChainNode<T>* next = nullptr) : data(item), link(nullptr) {}
private:
	T data;
	ChainNode<T>* link;
};

template <typename T>
class Chain {
public:
	Chain() : first(nullptr), last(nullptr) {}
	void InsertBack(const T& item) {
		if (first) {  // nonempty
			last->link = new ChainNode<T>(item);
			last = last->link;
		}
		else {
			first = last = new ChainNode<T>(item);
		}
	};
	void Concatenate(Chain<T>& c) {
		if (first) {  // this 是否為nonempty
			last->link = c.first;
			last = c.last;
		}
		else {
			first = c.first;
			last = c.last;
		}
		c.first = c.last = nullptr;  // empty c
	};

	/* 反轉鏈結串列
	 1. 使用三個指標：current、previous、r
	2. current:指向當前節點位置、previous:指向current前一個節點位置、
	r:存放previous的位置，因為previous會被current覆蓋掉，所以需要一個暫存變數r來保存previous的位置
	 r、p、c
	*/
	void Reverse() {
		ChainNode<T>* current = first, * previous = nullptr;
		last = first;  // 反轉後的最後一個節點是原來的第一個節點
		while (current) {
			ChainNode<T>* r = previous;
			previous = current;
			current = current->link;
			previous->link = r;
		}
		first = previous;
	};
	void Print() const {
		for (ChainNode<T>* current = first; current; current = current->link) {
			std::cout << current->data << std::endl;
		}
	};
private:
	ChainNode<T>* first;
	ChainNode<T>* last;
};

template <typename T>
class CircularList {
public:
	CircularList() : head(nullptr), last(nullptr) {}
	~CircularList() {
		if (!last) return;  // 空串列

		ChainNode<T>* current = last->link;  // head
		ChainNode<T>* nextNode;

		// 先把環打斷
		last->link = nullptr;

		while (current) {
			nextNode = current->link;
			delete current;      
			current = nextNode;
		}

		head = nullptr;
		last = nullptr;
	}

	void InsertFront(const T& item) {
		ChainNode<T>* newNode = GetNode();
		newNode->data = item;

		if (!last) {  // empty list
			head = last = newNode;
			last->link = newNode;  
		}
		else {
			newNode->link = last -> link;
			last->link = head = newNode;  // head always points to the first node、last->link points to the first node
		}
	};

	void InsertBack(const T& item) {
		ChainNode<T>* newNode = GetNode();
		newNode->data = item;
		if (!last) {       // 空指標
			head = last = newNode;
			last->link = newNode;
		}
		else {
			last->link = newNode;
			newNode->link = head;
			last = newNode;
		}
	};

	void DeleteFront() {
		if (!last) return;
		ChainNode<T>* first = last->link;

		if (first == last) {
			last = nullptr;
			head = nullptr;
		}
		else {
			head = last->link = first->link;
		}

		RetNode(first);  // ⭐ 收回節點
	}

	ChainNode<T>* GetNode() {
		if (av) {
			ChainNode<T>* temp = av;
			av = av->link;
			return temp;
		}
		else {
			return new ChainNode<T>();
		}
	}

	void RetNode(ChainNode<T>* x) {
		x->link = av;
		av = x;
		x->data = T{};  // reset data to default value
	}

	ChainNode<T>* GetHead() const { return head; }
	ChainNode<T>* GetHeadNext() const { return head->link; }
	ChainNode<T>* GetLast() const { return last; }
	ChainNode<T>* GetAv() const { return av; }
private:
	ChainNode<T>* head;
	ChainNode<T>* last;
	static ChainNode<T>* av;
};

template<typename T>
ChainNode<T>* CircularList<T>::av = nullptr;


