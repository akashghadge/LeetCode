/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ans;
        vector<int> split;
        int count =0;
        while(num){
            split.push_back((num%10)*(pow(10,count)));
            num=num/10;
            count++;
        }
        
        for(int j=split.size()-1;j>=0;j--){
            cout<<split[j]<<endl;
            if(split[j]>=1000){
                for(int i=0;i<split[j]/1000;i++){
                    ans= ans+"M";
                }
            } else if(split[j]>=500){
                if(split[j]==900){
                    ans= ans+"CM";
                } else if(split[j]==500)
                {
                    ans= ans+"D";
                }else{
                    ans= ans+"D";
                    for(int i=0;i<(split[j]-500)/100;i++){
                    ans= ans+"C";
                    }
                }
            }else if(split[j]>=100){
                if(split[j]==400){
                    ans= ans+"CD";
                } else if(split[j]==100){
                    ans= ans+"C";
                } else{
                    for(int i=0;i<(split[j])/100;i++){
                    ans= ans+"C";
                    }
                }
            }else if(split[j]>=50){
                 if(split[j]==90){
                    ans= ans+"XC";
                } else if(split[j]==50){
                    ans= ans+"L";
                } else{
                    ans= ans+"L";
                    for(int i=0;i<(split[j]-50)/10;i++){
                    ans= ans+"X";
                    }
                }
                
            }else if(split[j]>=10){
                if(split[j]==40){
                    ans= ans+"XL";
                } else if(split[j]==10){
                    ans= ans+"X";
                } else{
                    for(int i=0;i<(split[j])/10;i++){
                    ans= ans+"X";
                    }
                }
                
            }else if(split[j]>=5){
                if(split[j]==9){
                    ans= ans+"IX";
                } else if(split[j]==5){
                    ans= ans+"V";
                } else{
                    ans= ans+"V";
                     for(int i=0;i<(split[j]-5);i++){
                    ans= ans+"I";
                    }
                }
                
            }else if(split[j]>=1){
                if(split[j]==4){
                    ans= ans+"IV";
                } else if(split[j]==1){
                    ans= ans+"I";
                } else{
                     for(int i=1;i<=(split[j]);i++){
                    ans= ans+"I";
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
}