/*  QUESTION
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/
#include <vector>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        
        vector<int> map(128, 0);
        int count = t.length();
        int start = 0, minStart = 0, minLen = INT_MAX;
        
        // Build the frequency map for characters in t
        for (char c : t) map[c]++;
        
        // Expand the window with end
        for (int end = 0; end < s.length(); end++) {
            if (map[s[end]]-- > 0) count--;
            
            // Contract the window with start
            while (count == 0) {
                if (end - start + 1 < minLen) {
                    minStart = start;
                    minLen = end - start + 1;
                }
                
                if (map[s[start++]]++ == 0) count++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << sol.minWindow(s, t) << endl; // Output: "BANC"
    return 0;
}
