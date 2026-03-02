// ChainNode.h: 標準系統 include 檔案的 include 檔案，
// 或專案專屬的 Include 檔案。

#pragma once

template <typename T> class Chain;

template <typename T>
class ChainNode {
	friend class Chain<T>;
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
	void InsertBack(const T& item);
	void Concatenate(Chain<T>& c);
	void Reverse();
	void Print() const;
private:
	ChainNode<T>* first;
	ChainNode<T>* last;
};