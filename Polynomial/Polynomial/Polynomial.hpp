#pragma once

#define MaxDegree 100 // 皚程Ω计

class Polynomial {
private:
	int degree;  // 兜Α程玒计 degree <= MaxDegree
	float *coef; // 兜Α玒计
public:
	Polynomial(int d) : degree(d) {
		coef = new float[MaxDegree + 1];
	}

	~Polynomial() {
		delete[] coef;
	}
};