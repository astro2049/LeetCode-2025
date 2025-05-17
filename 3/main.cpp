#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        unordered_set<char> set;
        for (int i = 0, j = 0; j < s.length();) {
            if (set.find(s[j]) != set.end()) {
                while (s[i] != s[j]) {
                    set.erase(s[i]);
                    i++;
                }
                set.erase(s[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            set.insert(s[j]);
            j++;
        }

        return maxLen;
    }
};
