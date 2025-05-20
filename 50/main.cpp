#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        } else if (x == 1) {
            return 1;
        }
        return ponPon(x, n);
    }

    double ponPon(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        } else if (n == -1) {
            return 1 / x;
        }
        double halfPow = ponPon(x, n / 2);
        return halfPow * halfPow * ponPon(x, n % 2);
    }
};
