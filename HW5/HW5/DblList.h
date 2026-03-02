#pragma once
#include "GenericIterator.h"

template <typename T> class DblList;
template <typename T> struct DblListNodeTraits;

template <typename T>
class DblListNode {
	friend class DblList<T>;
	friend struct DblListNodeTraits<DblListNode<T>>;
public:
	DblListNode() : left(nullptr), right(nullptr) {}
	DblListNode(T item) : data(item), left(nullptr), right(nullptr) {}
private:
	T data;
	DblListNode<T> *left, *right;
};

//----------------------------------------------------------------


template <typename T>
struct DblListNodeTraits<DblListNode<T>> {
	using NodeType = DblListNode<T>;

	static NodeType* next(NodeType* node) {
		return node->right;   // 用 right 當 forward
	}

	static T& data(NodeType* node) {
		return node->data;
	}
};

//----------------------------------------------------------------

template <typename T>
class DblList {
public:
	DblList() : head(nullptr) {}

	using DblListIterator =
		GenericIterator<DblListNode<T>, DblListNodeTraits<DblListNode<T>>>;
	DblListIterator Begin() const { return DblListIterator(head); }
	DblListIterator End() const { return DblListIterator(nullptr); }

	void InsertFront(const T& item) {
		DblListNode<T>* newNode = new DblListNode<T>;
		newNode->data = item;
		if (!head) {  // 空串列
			newNode->left = newNode->right = newNode;  // 指向自己形成環
			head = newNode;
		}
		else {
			Insert(newNode, head->left);  // 插入到最後一個節點的右邊
			head = newNode;  // 更新head指向新的第一個節點
		}
	}
	// 插入節點p到節點x的右邊
	void Insert(DblListNode<T> *p, DblListNode<T> *x) {
		p->left = x; p->right = x->right; 
		x->right->left = p; x->right = p; 
	}
	void Delete(DblListNode<T> *x) {
		if (x == head) throw "Deletion of header node not permited";
		else {
			x->left->right = x->right;
			x->right->left = x->left;
			delete x;
		}
	}
	DblListNode<T>* GetHead() const { return head; }
private:
	DblListNode<T> *head;

};