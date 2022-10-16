/*
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

 

Example 1:


Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
 

Constraints:

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dp[301][11];
    long long f(vector<int>& j, int d,int i){
        if(i==j.size()) return INT_MAX;
        if(d==1){
            int m=INT_MIN;
            for(int k=i;k<j.size(); k++){
                m=max(m,j[k]);
            }
            return m;
        }
        if(dp[i][d]!=-1) return dp[i][d];

        long long v=INT_MIN,ans=INT_MAX;

        for(int k=i; k<j.size(); k++){
            if(v<j[k]) v=j[k];
            long long l=f(j,d-1,k+1);
            if(ans>l+v) ans=l+v;
        }

        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& j, int d) {
        if(j.size()<d) return -1;
        memset(dp,-1,sizeof(dp));
        return f(j,d,0);
    }

};
int main()
{
}