#include "stack.hpp"
#include <iostream>

int main() {
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	while (!s.IsEmpty()) {
		std::cout << s.Top() << std::endl;
		s.pop();
	}
	return 0;
}