
#include <iostream>
#include <vector>


using namespace std;
#define MAX_LEN 1000
using IntArray1000 = int[MAX_LEN];

class Factorial {
public:
    struct BigInt {
        IntArray1000 digits;
        int first;   // 第一個有效 digit index
        BigInt() {
            reset();
        }

        inline void reset() {
            std::memset(digits, 0, sizeof(digits));
            first = MAX_LEN-1;
            digits[first] = 1; // 初始值 = 1
        }

        BigInt& operator=(const BigInt& rhs) {
            if (this != &rhs) {
                this->first = rhs.first;
                memcpy(this->digits, rhs.digits, sizeof(this->digits));
            }
            return *this;
        }
    };

    explicit Factorial(int n) : n_(n){}
    
    void compute() {
        BigInt value; // 當前 factorial 值

        for (int i = 1; i <= n_; ++i) {
            multiply(value, i);
            std::cout << i << "! = ";
            print(value);
            std::cout << "\n";
        }
    }

private:
    BigInt countArray;
    int n_;    // n!

    void multiply(BigInt& a, int m) {
        int carry = 0;

        // 從右到左完整乘
        for (int i = MAX_LEN - 1; i >= a.first; --i) {
            int v = a.digits[i] * m + carry;
            a.digits[i] = v % 10;
            carry = v / 10;
        }

        // 處理最高位 carry
        while (carry > 0 && a.first >= 0) {
            a.digits[--a.first] = carry % 10;
            carry /= 10;
        }
    }

    void print(const BigInt& a) const {
        for (int i = a.first; i < MAX_LEN; ++i) {
            std::cout << a.digits[i];
        }
    }
};

int main() {
    Factorial fact(50);
    fact.compute();
}

