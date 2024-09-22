/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool valid(unordered_map<char, int> &a, unordered_map<char, int> &b)
    {
        for (auto val : b)
        {
            if (val.second > a[val.first])
                return false;
        }
        return true;
    }
    long long validSubstringCount(string a, string b)
    {
        unordered_map<char, int> mp;
        for (auto ch : b)
            mp[ch]++;
        int m = b.size(), n = a.size();
        long long ans = 0;
        int start = 0, i = 0;
        unordered_map<char, int> curr;
        while (i < n)
        {
            while (i < n and !valid(curr, mp))
            {
                curr[a[i]]++;
                i++;
            }
            if (valid(curr, mp))
                ans += (n - i) + 1;
            curr[a[start]]--;
            start++;
        }
        while (start < n)
        {
            if (valid(curr, mp))
                ans++;
            curr[a[start]]--;
            start++;
        }
        return ans;
    }
};
int main()
{
}