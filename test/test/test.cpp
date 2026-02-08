#include <iostream>

using namespace std;

int main() {
    int n = 1;
    cout << "Calcutating factorial of :" << endl;
    int c = 0;
    int numbers[50] = { 0 };
    while (n != 0) {
        cin >> n;
        numbers[c] = n;
        c++;
    }
    cout << "Answers :";
    for (int idx = 0; idx < c; idx++) {
        if (numbers[idx] == 0) return 0;
        n = numbers[idx];
        int A[80] = { 0 };
        int from = 79;                /* tarageting the strating position of array A*/
        A[79] = 1;
        cout << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 80; j++) {
                if (A[j] == 0) continue;
                A[j] = A[j] * i;
                /*
                if (j < from) {
                    from = j;               /* Renew from 
                }
                 */
            }
            for (int j = 79; j >= from; j--) {
                if ((A[j] / 10) > 0 && j > 0) {
                    A[j - 1] += A[j] / 10;
                    if (j == from) from--;
                }
                A[j] %= 10;
            }
            cout << i << "!=";
            for (int i = from; i < 80; i++) {
                cout << A[i];
            }
            cout << endl;
        }
    }
    return 0;
}