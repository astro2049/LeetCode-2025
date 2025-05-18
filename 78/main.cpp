#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> combos;
    vector<int> nums;

    vector<vector<int>> subsets(vector<int> &aNums) {
        nums = aNums;
        vector<int> combo;
        choose(0, combo);
        return combos;
    }

    void choose(int i, vector<int> &combo) {
        if (i == nums.size()) {
            combos.push_back(combo);
            return;
        }
        choose(i + 1, combo);
        combo.push_back(nums[i]);
        choose(i + 1, combo);
        combo.pop_back();
    }
};
