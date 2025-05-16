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
    int minEatingSpeed(const vector<int> &piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        int minSpeed = INT_MAX;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (canFinish(mid, piles, h)) {
                minSpeed = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return minSpeed;
    }

    bool canFinish(int speed, const vector<int> &piles, int hours) {
        for (const auto &pile: piles) {
            int time = pile / speed;
            if (pile % speed != 0) {
                time++;
            }
            hours -= time;
            if (hours < 0) {
                return false;
            }
        }
        return true;
    }
};
