#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int n;
    vector<string> parentheses;

    vector<string> generateParenthesis(int n) {
        this->n = n;

        generate(n, 0, "");

        return parentheses;
    }

    void generate(int lefts, int unclosedLefts, string s) {
        if (s.length() == n * 2) {
            parentheses.push_back(s);
            return;
        }
        if (lefts > 0) {
            generate(lefts - 1, unclosedLefts + 1, s + "(");
        }
        if (unclosedLefts > 0) {
            generate(lefts, unclosedLefts - 1, s + ")");
        }
    }
};
