#include <iostream>

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
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return nullptr;
        }

        traverse(root);
        return root;
    }

    void traverse(TreeNode *n) {
        TreeNode *left = n->left;
        n->left = n->right;
        n->right = left;

        if (n->left) {
            traverse(n->left);
        }
        if (n->right) {
            traverse(n->right);
        }
    }
};
