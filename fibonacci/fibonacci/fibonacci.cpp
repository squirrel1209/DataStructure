#include <iostream>
/*
fn = 0 if n = 0
fn = 1 if n = 1
fn = fn-1 + fn-2 if n >= 2
*/
using namespace std;

int interativeFib(int n) {
    if (n <= 1) return n;
    int lofib = 0;
    int hifib = 1;
    for (int i = 2; i <= n; i++) {
        int x = lofib;
        lofib = hifib;
        hifib = x + lofib;
    }
    return hifib;
}

int recursiveFib(int n) {
    if (n <= 1) return n;
    else return (recursiveFib(n - 1) + recursiveFib(n - 2));
}

int main() {
    
}

