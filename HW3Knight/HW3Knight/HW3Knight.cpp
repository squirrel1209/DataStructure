// HW3Knight.cpp: 定義應用程式的進入點。
//

#include "HW3Knight.h"

Knight::Knight(int n) : size(n) {
	checkerboard.resize(size, vector<int>(size, 0));
}
// True 表示合法移動 
inline bool Knight::isValidMove(int i, int j) const {
	// 檢查位置 (i, j)   是否在棋盤範圍內            且      未被拜訪過
	return (i >= 0 && i < size && j >= 0 && j < size && checkerboard[i][j] == 0);
}

bool Knight::run() {
	// 一開始
	int i = 0, j = 0;
	int moveIndex = 0;
	bool found = false;
	const int movesSize = moves.size();
	checkerboard[i][j] = moveCount++;

	while ( moveCount <= (size * size)) {
		for (int walk = moveIndex; walk < movesSize; ++walk) {
			int next_i = i + moves[walk].first;
			int next_j = j + moves[walk].second;

			if (isValidMove(next_i, next_j)) {
				// 符合範圍且未拜訪過
				checkerboard[next_i][next_j] = moveCount++;
				s.push({ i, j, walk });

				found = true;
				i = next_i;
				j = next_j;
				moveIndex = 0; // 重置方向編號，從頭開始找
				break;
			}
		}
	
		// 無法前進
		if (found == false) {
			if (s.IsEmpty()) {return false;}

			else {
				MoveState lastMove = s.Top();
				s.pop();
				checkerboard[i][j] = 0; // 回溯，清除拜訪紀錄
				i = lastMove.i;
				j = lastMove.j;
				moveCount--;
				moveIndex = lastMove.direction;
				moveIndex++;
			}
		}

		found = false; // 重置found狀態，繼續尋找下一步
	}
	return true;
}

void Knight::printBoard() const {
	int size = checkerboard.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << checkerboard[i][j] << "\t";
		}
		cout << endl;
	}
}


int main() {
	Knight knight(5);
	bool complete = knight.run();
	if (complete) {
		cout << "Knight's tour completed successfully!" << endl;
		knight.printBoard();
	} else {
		cout << "Knight's tour could not be completed." << endl;
	}
	return 0;
}