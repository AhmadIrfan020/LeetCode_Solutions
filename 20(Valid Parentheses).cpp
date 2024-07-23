/* QUESTION
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid. An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false
*/
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Stack to store opening brackets
        stack<char> st;
        
        // Iterate over each character in the string
        for (char c : s) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            // If it's a closing bracket
            else if (c == ')' || c == ']' || c == '}') {
                // Check if the stack is empty or the top of the stack does not match the closing bracket
                if (st.empty() || 
                    (c == ')' && st.top() != '(') ||
                    (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{')) {
                    return false;
                }
                // If it matches, pop the top of the stack
                st.pop();
            }
        }
        
        // If the stack is empty, all brackets matched properly
        return st.empty();
    }
};

int main() {
    Solution solution;

    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";

    cout << boolalpha; // For printing 'true'/'false' instead of '1'/'0'
    cout << "Is \"" << s1 << "\" valid? " << solution.isValid(s1) << endl;
    cout << "Is \"" << s2 << "\" valid? " << solution.isValid(s2) << endl;
    cout << "Is \"" << s3 << "\" valid? " << solution.isValid(s3) << endl;

    return 0;
}
