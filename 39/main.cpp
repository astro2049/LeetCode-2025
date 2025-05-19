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
    int target;
    vector<int> candidates;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        this->target = target;
        this->candidates = candidates;
        vector<int> combo;
        choose(0, 0, combo);
        return combos;
    }

    void choose(int i, int sum, vector<int> &combo) {
        if (sum > target || i == candidates.size()) {
            return;
        } else if (sum == target) {
            combos.push_back(combo);
            return;
        }
        sum += candidates[i];
        combo.push_back(candidates[i]);
        choose(i, sum, combo);
        sum -= candidates[i];
        combo.pop_back();
        choose(i + 1, sum, combo);
    }
};
