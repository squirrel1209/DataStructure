// BinaryTree.h: 標準系統 include 檔案的 include 檔案，
// 或專案專屬的 Include 檔案。

#pragma once

#include <iostream>
#include <queue>
template <typename T> class Tree;

template <typename T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;
	TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
public:
	Tree() : root(nullptr) {}
	void insert(const T& value) {
		root = InsertNode(root, value);
	}
	TreeNode<T>* InsertNode(TreeNode<T>* node, const T& value) {
		if (!node) {
			node = new TreeNode<T>(value);
		} else if (value < node->data) {
			node->left = InsertNode(node->left, value);
		} else {
			node->right = InsertNode(node->right, value);
		}
		return node;
	}

	void Delete(const T& value) {
		root = DeleteNode(root, value);
	}

	TreeNode<T>* DeleteNode(TreeNode<T>* node, const T& value) {
		if (!node) return node;
		if (value < node->data) {
			node->left = DeleteNode(node->left, value);
		} 
		else if (value > node->data) {
			node->right = DeleteNode(node->right, value);
		} 
		else {
			// 左子樹為空
			if (!node->left) {  
				TreeNode<T>* temp = node->right;
				delete node;
				return temp;
			} 
			// 右子樹為空
			else if (!node->right) {
				TreeNode<T>* temp = node->left;
				delete node;
				return temp;
			}
			// 兩個子樹都存在，找到左子樹的最大值
			TreeNode<T>* temp = node->left;
			while (temp->right) {
				temp = temp->right;
			}
			node->data = temp->data; // 替換值
			node->left = DeleteNode(node->left, temp->data); // 刪除替換的節點
		}
		return node;
	}

	void Preorder() const {
		Preorder(root);
	}
	void Preorder(TreeNode<T>* node) const {
		if (node) {
			std::cout << node->data << " ";
			Preorder(node->left);
			Preorder(node->right);
		}
	}

	void Inorder() const {
		Inorder(root);
	}

	void Inorder(TreeNode<T>* node) const {
		if (node) {
			Inorder(node->left);
			std::cout << node->data << " " ;
			if (node->left) std::cout << node->left->data << " " ;
			else std::cout << "0" << " ";
			if (node->right) std::cout << node->right->data  << std::endl;
			else std::cout << "0" << std::endl;
			Inorder(node->right);
		}
	}

	void Postorder() const {
		Postorder(root);
	}

	void Postorder(TreeNode<T>* node) const {
		if (node) {
			Postorder(node->left);
			Postorder(node->right);
			std::cout << node->data << " ";
		}
	}

	void LevelOrder() const {
		if (!root) return;
		std::queue<TreeNode<T>*> q;
		q.push(root);
		
		while (!q.empty()) {
			TreeNode<T>* node = q.front();
			q.pop();
			std::cout << node->data << " ";
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		
	}

	bool BinarySearch(const T& value) const {
		return BinarySearch(root, value);
	}

	bool BinarySearch(TreeNode<T>* node, const T& value) const {
		if (!node) return false;
		if (node->data == value) return true;
		else if (value < node->data) return BinarySearch(node->left, value);
		else return BinarySearch(node->right, value);
	}
private:
	TreeNode<T>* root;
};
