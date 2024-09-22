/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool valid(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (b[i] > a[i])
                return false;
        }
        return true;
    }
    long long validSubstringCount(string a, string b)
    {
        vector<int> mp(26, 0);
        for (auto ch : b)
            mp[ch - 'a']++;
        int m = b.size(), n = a.size();
        long long ans = 0;
        int start = 0, i = 0;
        vector<int> curr(30, 0);
        while (start <= i and i < n)
        {
            while (i < n and !valid(curr, mp))
            {
                curr[a[i] - 'a']++;
                i++;
            }
            if (valid(curr, mp))
                ans += (n - i) + 1;
            curr[a[start] - 'a']--;
            start++;
        }
        while (start < n)
        {
            if (valid(curr, mp))
                ans++;
            curr[a[start] - 'a']--;
            start++;
        }
        return ans;
    }
};
int main()
{
}