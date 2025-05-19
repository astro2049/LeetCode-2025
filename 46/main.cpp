#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> combos;
    unordered_set<int> set;
    vector<int> combo;

    vector<vector<int>> permute(vector<int> &nums) {
        set = unordered_set<int>(nums.begin(), nums.end());
        choose();
        return combos;
    }

    void choose() {
        if (set.empty()) {
            combos.push_back(combo);
            return;
        }
        vector<int> choices(set.begin(), set.end());
        for (const auto choice: choices) {
            combo.push_back(choice);
            set.erase(choice);
            choose();
            combo.pop_back();
            set.insert(choice);
        }
    }
};
