/*
Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.


Example 1:

Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

Explanation
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]


Constraints:

0 <= value <= 104
At most 3 * 104 calls will be made to addNum and getIntervals.


Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?


*/
#include <bits/stdc++.h>
using namespace std;
class SummaryRanges
{
public:
    void addNum(int val)
    {
        if (map.count(val))
            return;

        const int lo = lowerKey(val);
        const int hi = higherKey(val);

        // {lo, map[lo][1]} + val + {hi, map[hi][1]} = {lo, map[hi][1]}
        if (lo >= 0 && hi >= 0 && map[lo][1] + 1 == val && val + 1 == hi)
        {
            map[lo][1] = map[hi][1];
            map.erase(hi);
            // {lo, map[lo][1]} + val = {lo, val}
            // (prevent adding duplicate entry by using '>=' instead of '==')
        }
        else if (lo >= 0 && map[lo][1] + 1 >= val)
        {
            map[lo][1] = max(map[lo][1], val);
        }
        else if (hi >= 0 && val + 1 == hi)
        {
            // Val + {hi, map[hi][1]} = {val, map[hi][1]}
            map[val] = {val, map[hi][1]};
            map.erase(hi);
        }
        else
        {
            map[val] = {val, val};
        }
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> intervals;
        for (const auto &[_, interval] : map)
            intervals.push_back(interval);
        return intervals;
    }

private:
    map<int, vector<int>> map; // {start: {start, end}}

    // Maximum in map < key
    int lowerKey(int key)
    {
        auto it = map.lower_bound(key); // Minimum in map >= key
        if (it == begin(map))
            return -1;
        return (--it)->first;
    }

    // Minimum in map > key
    int higherKey(int key)
    {
        const auto it = map.upper_bound(key); // Minimum in map > key
        if (it == cend(map))
            return -1;
        return it->first;
    }
};

int main()
{
}