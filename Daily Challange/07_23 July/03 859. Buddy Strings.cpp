/*
        859. Buddy Strings
        

        Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].


	For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


 
Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.


Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.


Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.


 
Constraints:


	1 <= s.length, goal.length <= 2 * 104
	s and goal consist of lowercase letters.
        */
        

        #include <bits/stdc++.h>
        using namespace std;
        class Solution {public:    bool buddyStrings(string a, string b) {        int n=a.size();        unordered_map<char,int> mp;        for(auto val:a)            mp[val]++;        for(auto val:b)        {            if(mp.find(val)!=mp.end())            {                mp[val]--;                if(mp[val]==0)                    mp.erase(val);            }            else            {                return false;            }        }        if(mp.size()!=0)            return false;        int cn=0;        for(int i=0;i<n;i++)        {            if(a[i]!=b[i])                cn++;        }        if(cn>2)            return false;        if(cn==0)        {            for(auto val:a)            {                if(mp.find(val)!=mp.end())                    return true;                mp[val]++;            }            return false;        }        return true;    }};
