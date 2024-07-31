/*  QUESTION
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise. 
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/
#include <iostream>
#include <cctype>    // For isalnum and tolower functions
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Move left pointer if not alphanumeric
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            // Move right pointer if not alphanumeric
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            // Compare characters in lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};

// Example usage:
int main() {
    Solution sol;
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    
    cout << boolalpha;  // To print bool values as true/false
    cout << "Is \"" << test1 << "\" a palindrome? " << sol.isPalindrome(test1) << endl;
    cout << "Is \"" << test2 << "\" a palindrome? " << sol.isPalindrome(test2) << endl;
    
    return 0;
}
