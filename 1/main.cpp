#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map; // num, index
        for (int i = 0; i < nums.size(); i++) {
            int supplement = target - nums[i];
            if (map.find(supplement) != map.end()) {
                return {i, map[supplement]};
            } else {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};
