/* QUESTION 
Given an integer n, return an array ans of length n + 1 
such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.
Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> result(n + 1, 0);

        // Base case: if n is 0, return the vector
        if (n == 0) {
            return result;
        }

        // Base cases:
        // Set the first two elements of the vector
        result[0] = 0;
        if (n >= 1) {
            result[1] = 1;
        }

        // Iterate from 2 to n
        for (int x = 2; x <= n; ++x) {
            // If 'x' is even, set the x-th element of the vector to
            // the (x / 2)-th element
            if (x % 2 == 0) {
                result[x] = result[x / 2];
            }
            // If x is odd, set the x-th element of the vector to
            // the (x / 2)-th element + 1
            else {
                result[x] = result[x / 2] + 1;
            }
        }

        // Return the final vector
        return result;
    }
};

// Main function to test the code
int main() {
    Solution solution;
    int n;

    std::cout << "Enter an integer: ";
    std::cin >> n;

    std::vector<int> result = solution.countBits(n);

    std::cout << "The number of 1's in the binary representation of numbers from 0 to " << n << " are: " << std::endl;
    for (int i = 0; i <= n; ++i) {
        std::cout << "Number " << i << ": " << result[i] << std::endl;
    }

    return 0;
}
