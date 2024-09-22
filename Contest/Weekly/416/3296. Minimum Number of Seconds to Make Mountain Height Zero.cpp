/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minNumberOfSeconds(int k, vector<int> &a)
    {
        priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<>> pq;
        for (auto val : a)
            pq.push({val, {1, val}});
        long long ans = 0;
        while (k > 0)
        {
            auto top = pq.top();
            pq.pop();
            k--;
            ans = top.first;
            long long curr = top.first + (top.second.second * (top.second.first + 1));
            top.second.first++;
            pq.push({curr, top.second});
        }
        return ans;
    }
};
int main()
{
}