#include "set.hpp"

Set::Set(const char* str) {
	for (int i = 0; i < MAX_SIZE; ++i)
		elements[i] = false;

	for (int i = 0; str[i] != false; ++i) {
		unsigned char c = static_cast<unsigned char>(str[i]);   //str[i] = 'a'
		elements[c] = true;
	}
}

// 相等
bool Set::operator==(const Set& other) const {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (elements[i] != other.elements[i]) return false;
	}
	return true;
}

// 聯集
Set Set::operator+(const Set& other) const {
	Set result;
	for (int i = 0; i < MAX_SIZE; ++i) {
		result.elements[i] = elements[i] | other.elements[i];
	}
	return result;
}

// 交集
Set Set::operator*(const Set& other) const {
	Set newElements;
	for (int i = 0; i < MAX_SIZE; i++) {
		newElements.elements[i] = elements[i] & other.elements[i];
	}
	return newElements;
}

// 差集
Set Set::operator-(const Set& other) const {
	Set newElements;
	for (int i = 0; i < MAX_SIZE; i++) {
		newElements.elements[i] = elements[i] & (!other.elements[i]);
	}
	return newElements;
}

// 包含
bool Set::operator>=(const Set& other) const {
	if (other == (*this * other)) return true;
	else return false;
}

// 屬於
bool Set::in(char c) const {
	int num = static_cast<unsigned char>(c);
	if (elements[num] == true) return true;
	else return false;
}
 
void Set::print() const {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (elements[i] != false)
			std::cout << (char)i;
	}
	std::cout << std::endl;
}
