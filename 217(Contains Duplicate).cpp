/* QUESTION
Given an integer array nums, return true if any value appears 
at least twice in the array, and return false if every element is distinct.
Example 1:
Input: nums = [1,2,3,1]
Output: true
Example 2:
Input: nums = [1,2,3,4]
Output: false
*/
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 1};

    bool result1 = solution.containsDuplicate(nums1);  // Should return false
    bool result2 = solution.containsDuplicate(nums2);  // Should return true

    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;

    return 0;
}
