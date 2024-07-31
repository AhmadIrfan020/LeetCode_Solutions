/* QUESTION
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode *children[26];
        string word;

        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (string word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->word = word;
        }
        
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) return;
        
        p = p->children[c - 'a'];
        if (!p->word.empty()) {
            result.push_back(p->word);
            p->word = "";  // Avoid duplicate entries
        }

        board[i][j] = '#';  // Mark the cell as visited
        
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        
        board[i][j] = c;  // Restore the cell
    }
};


int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> result = solution.findWords(board, words);
    for (string word : result) {
        cout << word << " ";
    }
    return 0;
}