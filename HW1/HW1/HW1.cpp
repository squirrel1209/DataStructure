#include <iostream>
#include <vector>
using namespace std;

class RubikSquare {
public:
    struct position {
        int row;
        int column;
    };

    RubikSquare(int n) : size(n), matrix(size, vector<int>(size, 0)) {}

    void generate() {
        position now{ 0, size / 2 };
        position last{ 0, size / 2 };

        for (int i = 1; i <= size * size; i++) {
            if (now.row < 0) now.row += size;           // 超出上邊界
            if (now.column < 0) now.column += size;     // 超出左邊界

            if (matrix[now.row][now.column] == 0) {    // 位置沒空
                matrix[now.row][now.column] = i;
            }
            else {                                     // 位置有數字
                now = last;
                now.row++;
                if (now.row >= size) now.row = 0;     // 防止越界
                matrix[now.row][now.column] = i;
            }

            last = now;
            now.row--;
            now.column--;
        }
    }

    void symUpAmdDown() {  // 上下對稱
        int top = 0;
        int bottom = size - 1;
        while (top < bottom) {
            for (int col = 0; col < size; col++) {
                swap(matrix[top][col], matrix[bottom][col]);
            }
            top++;
            bottom--;
        }
    }

    void symmetrical() {  // 左右對稱
        int left = 0;
        int right = size - 1;
        while (left < right) {
            for (int row = 0; row < size; row++) {
                swap(matrix[row][left], matrix[row][right]);
            }
            left++;
            right--;
        }
    }

    void transpose() {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void horizontalShift() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < (size / 2); j++) {
                swap(matrix[i][j], matrix[i][size-j-1]);
            }
        }
    }

    void rotate() {  // 旋轉
        transpose();
        horizontalShift();
    }


    void printMatrix() {
        cout << "\nanswer:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printUpAndDownAndLeftAndRight() {
        this -> symUpAmdDown();
        this -> printMatrix();
        this -> symmetrical();
        this -> printMatrix();
    }

private:
    int size;
    vector<vector<int>> matrix;
};

int main() {
    for (int i = 1; i <= 9; i += 2) {
        cout << "n=" << i << endl;
        RubikSquare r(i);
        r.generate();
        r.printMatrix();
        r.printUpAndDownAndLeftAndRight();

        // 90度
        r.rotate();
        r.printMatrix();
        r.printUpAndDownAndLeftAndRight();

        // 180度
        r.rotate();
        r.printMatrix();
        r.printUpAndDownAndLeftAndRight();

        // 270度
        r.rotate();
        r.printMatrix();
        r.printUpAndDownAndLeftAndRight();
    }
    return 0;
}
