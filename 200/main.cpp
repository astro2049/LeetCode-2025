#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<char>> grid;
    int m, n;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>> &aGrid) {
        grid = aGrid;
        m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0';
                    dfs(i, j);
                }
            }
        }
        return count;
    }

    void dfs(int i, int j) {
        for (const auto &direction: directions) {
            int ii = i + direction[0], jj = j + direction[1];
            if (ii < 0 || ii == m || jj < 0 || jj == n || grid[ii][jj] != '1') {
                continue;
            }
            grid[ii][jj] = '0';
            dfs(ii, jj);
        }
    }
};
