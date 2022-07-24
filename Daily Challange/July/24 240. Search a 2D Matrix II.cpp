/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109

*/
#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        for(int i=0;i<mat.size();i++)
        {
            int lo=0;
            int hi=mat[0].size()-1;
            int mid=0;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(mat[i][mid]==target)
                {
                    return true;
                }
                else if(mat[i][mid]<target)
                {
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }
        }
        return false;
        
    }
};
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        // start from the [first row, last column] element
        int i=0;
        int j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target) // target found
                return true;
            else if(matrix[i][j]>target) //target is smaller, go leftwards
                --j; // decrease the column index
            else // target is larger, go downwards
                ++i; // increase the row index
        }
        return false; // target not found
    }
};
int main()
{
}