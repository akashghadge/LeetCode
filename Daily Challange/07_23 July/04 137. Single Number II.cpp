/*
        137. Single Number II
        

        Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 
Example 1:
Input: nums = [2,2,3,2]
Output: 3
Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

 
Constraints:


	1 <= nums.length <= 3 * 104
	-231 <= nums[i] <= 231 - 1
	Each element in nums appears exactly three times except for one element which appears once.
        */
        

        #include <bits/stdc++.h>
        using namespace std;
class Solution {
public:
   int singleNumber(vector<int>& s) 
    {
    	vector<int> t(32);////Made a array contain 32 elements.
    	int sz = s.size();
    	int i, j, n;
    	for (i = 0; i < sz; ++i)
    	{
    		n = s[i];
    		for (j = 31; j >= 0; --j)
    		{
    			t[j] += n & 1;//Find the last digit.
    			n >>= 1;
    			if (!n)
    				break;
    	    }
        }
        int res = 0;
        for (j = 31; j >= 0; --j)
        {
            n = t[j] % 3;//"3" represents k times. 
            if (n)
                res += 1 << (31 - j);
        }
        return res;
    }
};