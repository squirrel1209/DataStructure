#include "Polynomial.h"
#include <iostream>


void Polynomial::InsertTerm(int coef, int exp) {
	Term* newTerm = new Term;
	newTerm->Set(coef, exp);

	if (!poly) {  // 如果多項式為空，直接插入
		poly = newTerm;
		return;
	}

	if (coef == 0) {  // 如果系數為零，不插入
		delete newTerm;
		return;
	}

	// 插入新項到適當位置，保持指數從大到小的順序
	Term* current = poly;
	Term* prev = nullptr;
	while (current && current->exp > exp) {
		prev = current;
		current = current->next;
	}

	if (current && current->exp == exp) {  // 如果指數相同，合併項
		current->coef += coef;
		delete newTerm;  // 不需要新項了
	}

	else {  // 插入新項
		newTerm->next = current;
		if (prev) {
			prev->next = newTerm;
		}
		else {
			poly = newTerm;  // 插入到頭部
		}
	}
}

Polynomial Polynomial::operator+(const Polynomial& b) const {
	Polynomial result;
	Term* aTerm = poly;
	Term* bTerm = b.poly;

	while (aTerm && bTerm) {
		if (aTerm->exp > bTerm->exp) {
			result.InsertTerm(aTerm->coef, aTerm->exp);
			aTerm = aTerm->next;
		}
		else if (aTerm->exp < bTerm->exp) {
			result.InsertTerm(bTerm->coef, bTerm->exp);
			bTerm = bTerm->next;
		}
		else {  // 指數相同，合併項
			int sumCoef = aTerm->coef + bTerm->coef;
			if (sumCoef != 0) {  // 只有非零項才插入
				result.InsertTerm(sumCoef, aTerm->exp);
			}
			aTerm = aTerm->next;
			bTerm = bTerm->next;
		}
	}
	// 處理剩餘的項
	while (aTerm) {
		result.InsertTerm(aTerm->coef, aTerm->exp);
		aTerm = aTerm->next;
	}
	while (bTerm) {
		result.InsertTerm(bTerm->coef, bTerm->exp);
		bTerm = bTerm->next;
	}
	return result;
}

Polynomial Polynomial::operator*(const Polynomial& b) const {
	Polynomial result;
	for (Term* aTerm = poly; aTerm; aTerm = aTerm->next) {
		for (Term* bTerm = b.poly; bTerm; bTerm = bTerm->next) {
			int newCoef = aTerm->coef * bTerm->coef;
			int newExp = aTerm->exp + bTerm->exp;
			result.InsertTerm(newCoef, newExp);
		}
	}
	return result;
}

void Polynomial::Print() const {
	if (!poly) {
		std::cout << "0" << std::endl;  // 如果多項式為空，輸出0
		return;
	}
	for (Term* t = poly; t; t = t->next) {
		std::cout << t->coef << "x^" << t->exp << " ";
	}
	std::cout << std::endl;
}

int main() {
	Polynomial p1, p2;
	p1.InsertTerm(2, 1);  
	p1.InsertTerm(7, 0);  


	p2.InsertTerm(-2, 1);  
	p2.InsertTerm(-7, 0);  

	Polynomial sum = p1 + p2;  // 預期輸出: 1x^5 2x^3 2x^2 3x^1
	sum.Print();  // 預期輸出: 1x^5 2x^3 2x^2 3x^1
	return 0;
}