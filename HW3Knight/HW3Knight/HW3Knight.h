// HW3Knight.h: 標準系統 include 檔案的 include 檔案，
// 或專案專屬的 Include 檔案
#pragma once

#include "stack.hpp"
#include <iostream>
#include <vector>

using namespace std;

struct Move {
	int di;          // delta i  位移量
	int dj;          // delta j 
};

// stack 元素紀錄的三項資訊
struct MoveState {
	int i;
	int j;
	int direction;  // 從(i,j)移動的方向編號，編號為movs的索引值
};


class Knight {
public:
	Knight(int n);
	void printBoard() const;
	bool isValidMove(int i, int j) const;
	bool run();
private:

	vector<vector<int>> checkerboard;
	int size;
	int moveCount = 1;

	Stack<MoveState> s;
	const vector<pair<int, int>> moves = {
		{-2,  1}, {-1,  2}, { 1,  2}, { 2,  1},
		{ 2, -1}, { 1, -2}, {-1, -2}, {-2, -1}
	};
};

