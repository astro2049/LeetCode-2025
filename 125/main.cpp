#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (!isAlphaNumeric(s[i])) {
                i++;
                continue;
            }
            if (!isAlphaNumeric(s[j])) {
                j--;
                continue;
            }

            if (isSame(s[i], s[j])) {
                i++, j--;
                continue;
            } else {
                return false;
            }
        }

        return true;
    }

    bool isAlphaNumeric(const char &c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    bool isSame(char a, char b) {
        if (a >= 'A' && a <= 'Z') {
            a -= 'A' - 'a';
        }
        if (b >= 'A' && b <= 'Z') {
            b -= 'A' - 'a';
        }
        return a == b;
    }
};
