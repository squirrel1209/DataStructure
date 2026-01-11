#include <iostream>
using namespace std;

struct A {
    char c;
    int i;
    short s;
};

struct B {
    int i;
    short s;
    char c;
};

int main() {
    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(B): " << sizeof(B) << endl;
}
