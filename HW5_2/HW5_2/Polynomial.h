#pragma once

using namespace std;

struct Term {
	int coef;   // 系數
	int exp;    // 指數
	Term* next;  // 指向下一個項的指標
	Term Set(int c = 0, int e = 0) { coef = c; exp = e; next = nullptr; return *this; }
};

class Polynomial {
public:
	Polynomial() : poly(nullptr) {}

	void InsertTerm(int coef, int exp);
	void Print() const;  // 用於打印多項式的函數
	// 相加多項式 *this(a) 和 b並回傳它們的總和
	Polynomial operator+(const Polynomial& b) const;
	Polynomial operator*(const Polynomial& b) const;
private:
	Term* poly;
};