/* QUESTION
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        
        // Sort the input array
        std::sort(nums.begin(), nums.end());
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate values
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicate values for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::vector<int> nums2 = {0, 1, 1};
    std::vector<int> nums3 = {0, 0, 0};

    std::vector<std::vector<int>> result1 = solution.threeSum(nums1);
    std::vector<std::vector<int>> result2 = solution.threeSum(nums2);
    std::vector<std::vector<int>> result3 = solution.threeSum(nums3);

    std::cout << "Result 1:" << std::endl;
    for (const auto& triplet : result1) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << std::endl;
    }

    std::cout << "Result 2:" << std::endl;
    for (const auto& triplet : result2) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << std::endl;
    }

    std::cout << "Result 3:" << std::endl;
    for (const auto& triplet : result3) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << std::endl;
    }

    return 0;
}
