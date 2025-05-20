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
    vector<vector<int>> grid;
    int m, n;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>> &aGrid) {
        grid = aGrid;
        m = grid.size(), n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 1;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        const auto [x, y] = q.front();
                        q.pop();
                        for (const auto &direction: directions) {
                            int xx = x + direction[0], yy = y + direction[1];
                            if (xx < 0 || xx == m || yy < 0 || yy == n || grid[xx][yy] != 1) {
                                continue;
                            }
                            q.emplace(xx, yy);
                            grid[xx][yy] = 0;
                            area++;
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
