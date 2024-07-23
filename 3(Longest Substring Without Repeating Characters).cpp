/* QUESTION
Given a string s, find the length of the longest 
substring without repeating characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            // If the character is already in the map, move the start pointer to the right of the previous occurrence
            if (charIndexMap.find(currentChar) != charIndexMap.end()) {
                start = max(start, charIndexMap[currentChar] + 1);
            }
            // Update the current character's index
            charIndexMap[currentChar] = end;
            // Calculate the max length
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "abcabcbb";
    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl; // Output: 3
    return 0;
}
