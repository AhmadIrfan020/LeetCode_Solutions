/*  QUESTION
Reverse bits of a given 32 bits unsigned integer.
Note:
Note that in some languages, such as Java, there is no unsigned integer type.
 In this case, both input and output will be given as a signed integer type. 
 They should not affect your implementation, as the integer's internal binary representation 
 is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 2 above, the input represents the signed integer -3 and the output 
represents the signed integer -1073741825.
Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, 
so return 3221225471 which its binary representation is 10111111111111111111111111111111.
*/
#include <iostream>
#include <bitset>
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;  // Shift the result left by 1 bit to make room for the next bit
            result |= n & 1;  // Add the least significant bit of n to result
            n >>= 1;  // Shift n right by 1 bit to process the next bit
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    uint32_t n;

    // Test case 1
    n = 0b00000010100101000001111010011100;
    std::cout << "Input: n = " << std::bitset<32>(n) << std::endl;
    std::cout << "Output: " << solution.reverseBits(n) << " (" << std::bitset<32>(solution.reverseBits(n)) << ")" << std::endl;

    // Test case 2
    n = 0b11111111111111111111111111111101;
    std::cout << "Input: n = " << std::bitset<32>(n) << std::endl;
    std::cout << "Output: " << solution.reverseBits(n) << " (" << std::bitset<32>(solution.reverseBits(n)) << ")" << std::endl;

    return 0;
}
