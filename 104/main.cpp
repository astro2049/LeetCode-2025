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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int depth = 1;
        traverse(root, 1, depth);

        return depth;
    }

    void traverse(TreeNode *n, int level, int &depth) {
        if (level > depth) {
            depth = level;
        }

        if (n->left) {
            traverse(n->left, level + 1, depth);
        }
        if (n->right) {
            traverse(n->right, level + 1, depth);
        }
    }
};
