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
    int directions[4][2] = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1}};

    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }

        int minute = 0;
        while (freshOranges != 0 && !q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                const auto [i, j] = q.front();
                q.pop();
                for (const auto &direction: directions) {
                    int ii = i + direction[0], jj = j + direction[1];
                    if (ii < 0 || ii == m || jj < 0 || jj == n || grid[ii][jj] != 1) {
                        continue;
                    }
                    q.emplace(ii, jj);
                    freshOranges--;
                    grid[ii][jj] = 2;
                }
            }

            minute++;
        }

        return freshOranges == 0 ? minute : -1;
    }
};
