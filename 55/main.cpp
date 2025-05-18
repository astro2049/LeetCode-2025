#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i] == 0) {
                return false;
            }
            if (i + nums[i] >= nums.size() - 1) {
                return true;
            }
            int bestProspect = 0, bestJ = i + 1;
            for (int j = i + 1; j <= i + nums[i]; j++) {
                int prospect = j + nums[j];
                if (prospect > bestProspect) {
                    bestProspect = prospect;
                    bestJ = j;
                }
            }
            i = bestJ;
        }

        return true;
    }
};
