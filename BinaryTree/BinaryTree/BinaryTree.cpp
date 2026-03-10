// BinaryTree.cpp: 定義應用程式的進入點。
//

#include "BinaryTree.h"

using namespace std;

int main() {
	Tree<int> tree;
	int arr[] = { 3, 3, 5, 9, 5, 3, 4, 8, 5, 3, 10, 10, 8 };
	for (int value : arr) {
		if (!tree.BinarySearch(value)) {
			tree.insert(value);
		}
		else
			tree.Delete(value);
	}

	tree.Inorder();
	return 0;
}
