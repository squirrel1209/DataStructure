
/*
n = 2
1.A -> C
2.A -> B
1.C -> B

n = 3
1.A -> C
2.A -> B
1.C -> B
3.A -> C
1.B -> A
2.B -> C
1.A -> C
*/
#include <iostream>

using namespace std;

// a source peg
// b target peg
// c auxiliary peg
void tower(int n, char a, char b, char  c) {
	if (n == 1) {
		cout << "move disk" << n << "from peg" << a << " -> " << c << endl;
		return;
	}

	tower(n - 1, a, c, b);
	cout << "move disk" << n << "from peg" << a << " -> " << c << endl;
	tower(n - 1, b, a, c);
}

int main() {
   
}


