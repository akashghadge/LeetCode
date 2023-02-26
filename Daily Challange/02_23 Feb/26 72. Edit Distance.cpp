/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string a, string b) {
        int n=a.size(),m=b.size();
        vector<int> prev(m + 1, 0),curr(m + 1, 0);
        for (int i = 0; i <= m; i++) prev[i] = i;
        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
                if (a[i - 1] == b[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = min(prev[j], min(curr[j - 1], prev[j - 1])) + 1;
            prev = curr;
        }
        return prev[m];
    }
};
int main()
{
}