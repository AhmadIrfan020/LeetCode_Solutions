/*  QUESTION
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the lengths of the strings are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Use a hash table to count the characters
        unordered_map<char, int> count;

        // Count characters in the first string
        for (char c : s) {
            count[c]++;
        }

        // Subtract character counts using the second string
        for (char c : t) {
            count[c]--;
        }

        // Check if all counts are zero
        for (const auto& entry : count) {
            if (entry.second != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s1 = "anagram";
    string s2 = "nagaram";
    bool result = solution.isAnagram(s1, s2);
    cout << (result ? "True" : "False") << endl;

    s1 = "cat";
    s2 = "rat";
    result = solution.isAnagram(s1, s2);
    cout << (result ? "True" : "False") << endl;
    return 0;
}
