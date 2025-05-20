#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int from2 = 1, from1 = 2;
        int ways;
        for (int i = 3; i <= n; i++) {
            ways = from2 + from1;
            from2 = from1;
            from1 = ways;
        }
        return ways;
    }
};
