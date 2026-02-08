#pragma once
#include <iostream>
#include <string.h>
#define MAX_SIZE 256
typedef bool ElementType[MAX_SIZE];


class Set {
public:
	Set( ) {
		for (int i = 0; i < MAX_SIZE; i++)
			elements[i] = false;
	}
    explicit Set(const char* str);

	/*
	Set(const Set& other) {
		for (int i = 0; i < MAX_SIZE; i++) {
			elements[i] = other.elements[i];
		}
	}
	*/
	~Set() {}

	// Copy assignment
	Set operator=(const Set& other) {
		for (int i = 0; i < MAX_SIZE; i++) {
			elements[i] = other.elements[i];
		}
		return *this;
	}

	// 相等
	bool operator==(const Set& other) const;
	// 聯集
	Set operator+(const Set& other) const;
	// 交集
	Set operator*(const Set& other) const;
	// 差集
	Set operator-(const Set& other) const;
	// 包含 A ⊇ B   A >= B ，B 的所有元素，都在 A 裡面
	// 
	bool operator>=(const Set& other) const;
	bool in(char c) const;
	void print() const;
private:
	ElementType elements;
};