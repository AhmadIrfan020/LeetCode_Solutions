/* QUESTION
The median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value, and the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
Example 1:
Input
Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/

#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Add to max-heap (left half)
        left.push(num);
        
        // Balance heaps: move the largest element from left to right
        right.push(left.top());
        left.pop();
        
        // Ensure left heap has more or equal number of elements
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        } else {
            return (left.top() + right.top()) / 2.0;
        }
    }
    
private:
    std::priority_queue<int> left; // Max-heap for the left half
    std::priority_queue<int, std::vector<int>, std::greater<int>> right; // Min-heap for the right half
};

int main() {
    MedianFinder medianFinder;
    
    medianFinder.addNum(1);
    std::cout << "Median after adding 1: " << medianFinder.findMedian() << std::endl;
    
    medianFinder.addNum(2);
    std::cout << "Median after adding 2: " << medianFinder.findMedian() << std::endl;
    
    medianFinder.addNum(3);
    std::cout << "Median after adding 3: " << medianFinder.findMedian() << std::endl;
    
    medianFinder.addNum(4);
    std::cout << "Median after adding 4: " << medianFinder.findMedian() << std::endl;
    
    medianFinder.addNum(5);
    std::cout << "Median after adding 5: " << medianFinder.findMedian() << std::endl;
    
    return 0;
}
