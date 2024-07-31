/* QUESTION
Serialization is the process of converting a data structure or object into a sequence of bits 
so that it can be stored in a file or memory buffer, or transmitted across a network connection 
link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization 
algorithm should work. You just need to ensure that a binary tree can be serialized to a string and 
this string can be deserialized to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
*/
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string data;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                data.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            } else {
                data.append("null,");
            }
        }
        
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(ss, item, ',')) {
                if (item == "null") {
                    node->left = nullptr;
                } else {
                    TreeNode* leftNode = new TreeNode(stoi(item));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }
            
            if (getline(ss, item, ',')) {
                if (item == "null") {
                    node->right = nullptr;
                } else {
                    TreeNode* rightNode = new TreeNode(stoi(item));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};


 int main() {
     Codec ser, deser;
     TreeNode* root = new TreeNode(1);
     root->left = new TreeNode(2);
     root->right = new TreeNode(3);
     root->right->left = new TreeNode(4);
     root->right->right = new TreeNode(5);
     
     string serialized = ser.serialize(root);
     TreeNode* deserialized = deser.deserialize(serialized);
     
     // Output the tree structure after deserialization
     queue<TreeNode*> q;
     q.push(deserialized);
     while (!q.empty()) {
         TreeNode* node = q.front();
         q.pop();
         if (node) {
             cout << node->val << " ";
             q.push(node->left);
             q.push(node->right);
         } else {
             cout << "null ";
         }
     }
     
     return 0;
 }
