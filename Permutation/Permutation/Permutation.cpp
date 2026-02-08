#include <iostream>

using namespace std;


void permutation(char* a, const int k, const int m) {
    if (k == m) {
        for (int i = 0; i <= m; i++) {
            cout << a[i];
        }
        cout << endl;
    }

    else {
        for (int i = k; i <= m; i++) {
            swap(a[k], a[i]);
            permutation(a, k + 1, m);
            swap(a[k], a[i]);
        }
    }
}

int main() {
    char a[] = "abcd";
    const int n = sizeof(a) / sizeof(a[0]) - sizeof(a[0]);
    permutation(a, 0, n-1);
}


