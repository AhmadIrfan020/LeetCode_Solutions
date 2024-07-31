/*  QUESTION
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and 
choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
*/
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;  // Buy pointer
        int right = 1; // Sell pointer
        int maxP = 0;  // Maximum profit

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                int profit = prices[right] - prices[left]; // Calculate profit
                maxP = max(maxP, profit);                 // Update maximum profit
            } else {
                left = right; // Update left pointer to right pointer
            }
            right++; // Move right pointer one step forward
        }

        return maxP;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl; // Output: 5
    return 0;
}
