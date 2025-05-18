#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        getRadius(root, diameter);
        return diameter;
    }

    int getRadius(TreeNode *n, int &diameter) {
        int leftRadius = n->left ? 1 + getRadius(n->left, diameter) : 0;
        int rightRadius = n->right ? 1 + getRadius(n->right, diameter) : 0;
        diameter = max(diameter, leftRadius + rightRadius);
        return max(leftRadius, rightRadius);
    }
};
