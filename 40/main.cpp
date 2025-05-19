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
    vector<vector<int>> combos;
    vector<int> candidates;
    int target;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());
        this->target = target;
        vector<int> combo;
        choose(0, 0, combo);
        return combos;
    }

    void choose(int i, int sum, vector<int> &combo) {
        if (sum == target) {
            combos.push_back(combo);
            return;
        } else if (sum > target || i == candidates.size()) {
            return;
        }
        sum += candidates[i];
        combo.push_back(candidates[i]);
        choose(i + 1, sum, combo);
        sum -= candidates[i];
        combo.pop_back();
        i++;
        while (i < candidates.size() && candidates[i - 1] == candidates[i]) {
            i++;
        }
        choose(i, sum, combo);
    }
};
