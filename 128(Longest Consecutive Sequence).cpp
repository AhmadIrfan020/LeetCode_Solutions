/*  QUESTION
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // For std::max
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : nums) {
            // Check if num is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;

                // Increment the current number to find the length of the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

                // Update the maximum length
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = sol.longestConsecutive(nums);
    cout << "Length of the longest consecutive elements sequence: " << result << endl; // Output: 4
    return 0;
}
