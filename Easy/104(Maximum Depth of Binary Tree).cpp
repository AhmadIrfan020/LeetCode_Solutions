/* QUESTION
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along
the longest path from the root node down to the farthest leaf node.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:
Input: root = [1,null,2]
Output: 2
*/
#include <iostream>
#include <vector>
#include <queue>

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
};

// Helper function to create a tree from a vector
TreeNode* createTree(const std::vector<int>& nodes, int i = 0) {
    if (i >= nodes.size() || nodes[i] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(nodes[i]);
    root->left = createTree(nodes, 2 * i + 1);
    root->right = createTree(nodes, 2 * i + 2);
    return root;
}

int main() {
    // Create test tree
    std::vector<int> rootNodes = {3, 9, 20, -1, -1, 15, 7};

    TreeNode* root = createTree(rootNodes);

    // Find maximum depth
    Solution sol;
    int depth = sol.maxDepth(root);
    std::cout << "Maximum Depth: " << depth << std::endl;

    // Clean up the allocated memory
    // Note: Proper memory management should be implemented for a complete solution.
    // For simplicity, this example does not include the deletion of created nodes.

    return 0;
}
