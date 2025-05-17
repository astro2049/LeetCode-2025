#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        int map1[26], map2[26];
        for (int i = 0; i < s1.length(); i++) {
            map1[getHash(s1[i])]++;
            map2[getHash(s2[i])]++;
        }

        int matchCount = 0;
        for (int i = 0; i < 26; i++) {
            if (map1[i] == map2[i]) {
                matchCount++;
            }
        }
        if (matchCount == 26) {
            return true;
        }

        for (int i = 0, j = s1.length(); j < s2.length(); i++, j++) {
            const char &ci = s2[i];
            if (hasSameCount(map1, map2, ci)) {
                matchCount--;
            }
            map2[getHash(ci)]--;
            if (hasSameCount(map1, map2, ci)) {
                matchCount++;
            }

            const char &cj = s2[j];
            if (hasSameCount(map1, map2, cj)) {
                matchCount--;
            }
            map2[getHash(cj)]++;
            if (hasSameCount(map1, map2, cj)) {
                matchCount++;
            }

            if (matchCount == 26) {
                return true;
            }
        }

        return false;
    }

    int getHash(const char &c) {
        return c - 'a';
    }

    bool hasSameCount(const int (&map1)[26], const int (&map2)[26], const char &c) {
        return map1[getHash(c)] == map2[getHash(c)];
    }
};
