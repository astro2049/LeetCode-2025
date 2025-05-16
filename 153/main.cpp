#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[0] <= nums.back()) {
            return nums[0];
        }

        int i = 1, j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[0] < nums[mid]) {
                i = mid + 1;
            } else if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            } else {
                j = mid - 1;
            }
        }

        return -1;
    }
};
