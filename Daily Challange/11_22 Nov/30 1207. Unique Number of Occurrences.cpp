/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.



Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true


Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
Accepted
234.2K
Submissions
317.8K

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        // make a map and store the count
        unordered_map<int, int> mp;
        for (auto i : arr)
        {
            mp[i]++;
        }
        // use a set and store the count and compare the size of map and set
        unordered_set<int> s;
        for (auto x : mp)
        {
            s.insert(x.second);
        }

        if (mp.size() == s.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
}