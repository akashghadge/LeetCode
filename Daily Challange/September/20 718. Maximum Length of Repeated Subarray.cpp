/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		if(size(A) < size(B)) A.swap(B); 
		int m = size(A), n = size(B), ans = 0, dp[2][n+1]; 
		memset(dp, 0, sizeof dp);
		for(int i = 1, cur = 1, prev{}; i <= m; i++, cur ^= 1, prev ^= 1) 
			for(int j = 1; j <= n; j++) 
				dp[cur][j] = A[i-1] == B[j-1] ? dp[prev][j-1] + 1 : 0,
				ans = max(ans, dp[cur][j]);

		return ans;
	}
};	

int main()
{
}