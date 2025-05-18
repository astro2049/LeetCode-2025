#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (const auto &num: nums) {
            add(num);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
