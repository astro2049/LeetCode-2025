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
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> combos;
        for (int i = 0; i < nums.size();) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) {
                        j++;
                    }
                } else if (sum == 0) {
                    combos.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) {
                        j++;
                    }
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else {
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
            i++;
            while (i < nums.size() && nums[i - 1] == nums[i]) {
                i++;
            }
        }

        return combos;
    }
};
