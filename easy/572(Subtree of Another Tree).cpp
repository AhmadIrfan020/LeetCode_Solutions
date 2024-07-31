/* QUESTION
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root 
with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
The tree tree could also be considered as a subtree of itself.
Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
*/

#include <iostream>
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        if (same(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool same(TreeNode* r, TreeNode* s) {
        if (r == nullptr && s == nullptr) {
            return true;
        }
        if (r == nullptr || s == nullptr) {
            return false;
        }
        if (r->val != s->val) {
            return false;
        }
        return same(r->left, s->left) && same(r->right, s->right);
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
    // Create test trees
    std::vector<int> rootNodes = {3, 4, 5, 1, 2};
    std::vector<int> subRootNodes = {4, 1, 2};

    TreeNode* root = createTree(rootNodes);
    TreeNode* subRoot = createTree(subRootNodes);

    // Check if subRoot is a subtree of root
    Solution sol;
    bool result = sol.isSubtree(root, subRoot);
    std::cout << (result ? "true" : "false") << std::endl;

    // Clean up the allocated memory
    // Note: Proper memory management should be implemented for a complete solution.
    // For simplicity, this example does not include the deletion of created nodes.

    return 0;
}
