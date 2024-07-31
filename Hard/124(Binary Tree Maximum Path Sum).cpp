/* QUESTION
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/
#include <iostream>
#include <climits>
using namespace std;

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
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        maxPathSumHelper(root, globalMax);
        return globalMax;
    }
    
private:
    int maxPathSumHelper(TreeNode* node, int& globalMax) {
        if (!node) return 0;
        
        // Recursively get the max sum of the left and right subtrees
        int leftMax = max(0, maxPathSumHelper(node->left, globalMax));
        int rightMax = max(0, maxPathSumHelper(node->right, globalMax));
        
        // Current max path includes the node itself and possibly its left and right subtrees
        int currentMax = node->val + leftMax + rightMax;
        
        // Update the global max path sum
        globalMax = max(globalMax, currentMax);
        
        // Return the max sum path that starts from the current node and extends to one of its subtrees
        return node->val + max(leftMax, rightMax);
    }
};

// Example usage
int main() {
    Solution sol;
    TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Maximum path sum: " << sol.maxPathSum(root1) << endl; // Output: 6
    
    TreeNode* root2 = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << "Maximum path sum: " << sol.maxPathSum(root2) << endl; // Output: 42
    
    return 0;
}
