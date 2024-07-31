/* QUESTION
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Initialize dp array
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        // Fill the dp array using the relation dp[i] = dp[i - 1] + dp[i - 2]
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the number of steps: ";
    cin >> n;

    int result = solution.climbStairs(n);
    cout << "Number of distinct ways to climb to the top: " << result << endl;

    return 0;
}
