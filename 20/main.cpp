#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {{')', '('},
                                         {']', '['},
                                         {'}', '{'},};
        stack<char> stk;
        for (const auto &c: s) {
            if (map.find(c) == map.end()) { // one of left parentheses
                stk.push(c);
            } else { // one of right parentheses
                if (!stk.empty() && stk.top() == map[c]) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
