#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int from2 = cost[0], from1 = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int best = min(from2, from1) + cost[i];
            from2 = from1;
            from1 = best;
        }
        return min(from2, from1);
    }
};
