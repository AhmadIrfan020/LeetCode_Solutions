/*  QUESTION
You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
Example 2:
Input: height = [1,1]
Output: 1
*/
#include <vector>
#include <algorithm>
#include <iostream> // For demonstration purposes if you want to print the result

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;  // Initialize the result variable to store the maximum area
        int l = 0;  // Left pointer starts at the beginning of the array
        int r = height.size() - 1;  // Right pointer starts at the end of the array

        // Iterate until the two pointers meet
        while (l < r) {
            // Calculate the area formed between the two pointers
            int area = (r - l) * min(height[l], height[r]);
            // Update the result with the maximum area found so far
            res = max(res, area);
            
            // Move the pointer pointing to the shorter line to try and find a larger area
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;  // Return the maximum area found
    }
};

int main() {
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = solution.maxArea(height);
    cout << "The maximum amount of water a container can store is: " << result << endl;
    return 0;
}
