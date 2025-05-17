#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxGain = 0;
        for (int i = 0, j = 1; j < prices.size();) {
            if (prices[i] > prices[j]) {
                i = j;
                j++;
            } else {
                maxGain = max(maxGain, prices[j] - prices[i]);
                j++;
            }
        }

        return maxGain;
    }
};
