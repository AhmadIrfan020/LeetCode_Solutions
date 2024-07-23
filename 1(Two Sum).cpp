/*     Question 
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    */
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> prevMap;

        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i];
            if (prevMap.find(diff) != prevMap.end())
            {
                return {prevMap[diff], i};
            }
            prevMap[nums[i]] = i;
        }

        return {}; // Return an empty vector if no solution is found
    }
};

void printResult(const std::vector<int> &result)
{
    if (!result.empty())
    {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    }
    else
    {
        std::cout << "No two numbers found that add up to the target." << std::endl;
    }
}

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Example input 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Example 1: ";
    printResult(result1);

    // Example input 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Example 2: ";
    printResult(result2);

    // Example input 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Example 3: ";
    printResult(result3);

    return 0;
}