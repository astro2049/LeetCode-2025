#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> nums;
    vector<vector<int>> combos;
    vector<int> combo;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        choose(0);
        return combos;
    }

    void choose(int i) {
        if (i == nums.size()) {
            combos.push_back(combo);
            return;
        }
        combo.push_back(nums[i]);
        choose(i + 1);
        combo.pop_back();
        i++;
        while (i < nums.size() && nums[i - 1] == nums[i]) {
            i++;
        }
        choose(i);
    }
};
