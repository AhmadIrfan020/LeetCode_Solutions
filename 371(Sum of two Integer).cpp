/* QUESTION = SUM OF TWO INTEGER
    Given two integers a and b, return the sum of the two integers without using the operators + and -.

    Example 1:

    Input: a = 1, b = 2
    Output: 3
*/
#include <iostream>
class Solution
{
public:
    
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry = a & b; // Calculate carry
            a = a ^ b;         // Calculate sum without carry
            b = carry << 1;    // Update b to carry shifted left
        }
        return a;
    }
};

int main()
{
    Solution solution;

    // Test cases
    int a1 = 5, b1 = 3;
    std::cout << "Sum of " << a1 << " and " << b1 << " is: " << solution.getSum(a1, b1) << std::endl;

    int a2 = -1, b2 = 1;
    std::cout << "Sum of " << a2 << " and " << b2 << " is: " << solution.getSum(a2, b2) << std::endl;

    return 0;
}
