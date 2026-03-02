// Bag.cpp: 定義應用程式的進入點。
//

#include "Bag.h"

using namespace std;

Stack::Stack(int stackCapacity) : Bag(stackCapacity) {}
Stack::~Stack() {}

int Stack::Top() const
{
	if (IsEmpty()) {
		throw "Stack is empty.";
	}
	return array[top];
}

void Stack::Pop()
{
	if (IsEmpty()) {
		throw "Stack is empty.";
	}
	top--;
}

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
