#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    bool reportSpam(vector<string> &a, vector<string> &b)
    {
        unordered_map<string, int> mp;
        for (auto val : b)
        {
            mp[val]++;
        }
        int cn = 0;
        for (auto val : a)
        {
            if (mp[val] != 0)
            {
                cn++;
            }
        }
        return cn >= 2;
    }
};