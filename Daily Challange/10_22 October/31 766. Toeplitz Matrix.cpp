/*
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

 

Example 1:


Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:


Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99
 

Follow up:

What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i,j;
        int k = 1;


     while(k<m-1){
         j = k;
         i=0;
          while(i<n-1 && j<m-1 ){
         
         if(matrix[i][j]!=matrix[i+1][j+1])return false;
         i++;
         j++;

        }
        k++;
     }
      
     k=1;
     while(k<n-1){
         i = k;
         j = 0;
          while(i<n-1 && j<m-1 ){
         
         if(matrix[i][j]!=matrix[i+1][j+1])return false;
         i++;
         j++;

        }
        k++;
     }
     i=0;
     j=0;

        while(i<n && i<m){

            if(matrix[0][0]!=matrix[i][i])
              return false;
            
            i++;
        }
        
        return true;
    }
};

int main()
{
}