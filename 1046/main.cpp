#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y != x) {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
