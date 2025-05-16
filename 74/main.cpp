#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = m * n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            int ii = mid / n, jj = mid % n;
            if (matrix[ii][jj] < target) {
                i = mid + 1;
            } else if (matrix[ii][jj] == target) {
                return true;
            } else {
                j = mid - 1;
            }
        }

        return false;
    }
};
