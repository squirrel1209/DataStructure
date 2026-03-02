#include "Polynomial.h"

void Polynomial::InsertTerm(int coef, int exp) {
	Term* newTerm = new Term;
	newTerm->Set(coef, exp);

	if (!poly) {  // 如果多項式為空，直接插入
		poly = newTerm;
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
		} else {
			poly = newTerm;  // 插入到頭部
		}
	}
}

int main() {
	Polynomial p1;
	p1.InsertTerm(3, 2);  // 3x^2
	p1.InsertTerm(2, 1);  // 2x
	p1.InsertTerm(1, 0);  // 1

	return 0;
}