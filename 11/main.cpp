#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxArea(vector<int> &heights) {
        int maxCapacity = 0;
        for (int i = 0, j = heights.size() - 1; i < j;) {
            if (heights[i] <= heights[j]) {
                maxCapacity = max(maxCapacity, heights[i] * (j - i));
                i++;
            } else {
                maxCapacity = max(maxCapacity, heights[j] * (j - i));
                j--;
            }
        }

        return maxCapacity;
    }
};
