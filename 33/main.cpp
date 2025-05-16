#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int search(const vector<int> &nums, int target) {
        if (nums[0] <= nums.back()) {
            return binarySearch(0, nums.size() - 1, nums, target);
        }

        int i = 1, j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[0] < nums[mid]) {
                i = mid + 1;
            } else if (nums[mid - 1] > nums[mid]) {
                if (nums[0] <= target) {
                    return binarySearch(0, mid - 1, nums, target);
                } else {
                    return binarySearch(mid, nums.size() - 1, nums, target);
                }
            } else {
                j = mid - 1;
            }
        }

        return -1;
    }

    int binarySearch(int i, int j, const vector<int> &nums, int &target) {
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                j = mid - 1;
            }
        }

        return -1;
    }
};
