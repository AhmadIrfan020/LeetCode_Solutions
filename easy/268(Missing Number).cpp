/* QUESTION
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.
Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
*/
#include <vector>
#include <numeric> // For std::accumulate
#include <iostream>

using namespace std;

class Solution {
public:

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Calculate the expected sum of the first n natural numbers
        int totalSum = (n * (n + 1)) / 2;
        // Calculate the actual sum of the numbers in the array
        int actualSum = accumulate(nums.begin(), nums.end(), 0);
        // The missing number is the difference between the expected sum and the actual sum
        return totalSum - actualSum;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int result = solution.missingNumber(nums);
    cout << "The missing number is: " << result << endl;  // Output: 8
    return 0;
}
