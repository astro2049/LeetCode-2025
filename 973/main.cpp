#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Point {
public:
    int x;
    int y;
    int i;

    Point(int x, int y, int i) : x(x), y(y), i(i) {}
};

struct Compare {
    bool operator()(const Point &a, const Point &b) {
        return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<Point, vector<Point>, Compare> pq;
        for (int i = 0; i < points.size(); i++) {
            const auto &point = points[i];
            pq.emplace(point[0], point[1], i);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(points[pq.top().i]);
            pq.pop();
        }
        return res;
    }
};
