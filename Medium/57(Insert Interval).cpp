/* QUESTION 
You are given an array of non-overlapping intervals intervals where 
intervals[i] = [starti, endi] represent the start and
the end of the ith interval and intervals is sorted in ascending order by starti.
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order 
by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.
Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;

        // Step 1: Add all intervals that come before the new interval
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            merged.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]); // Start of merged interval
            newInterval[1] = max(newInterval[1], intervals[i][1]); // End of merged interval
            i++;
        }
        merged.push_back(newInterval); // Add the merged interval

        // Step 3: Add all remaining intervals
        while (i < intervals.size()) {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> result1 = solution.insert(intervals1, newInterval1);
    cout << "Output: ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> result2 = solution.insert(intervals2, newInterval2);
    cout << "Output: ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
