/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 0; i < points.size(); ++i) {
      unordered_map<pair<int, int>, int, pairHash> slopeCount;
      const vector<int> p1{points[i]};
      int samePoints = 1;
      int maxPoints = 0;  // Maximum number of points with the same slope
      for (int j = i + 1; j < points.size(); ++j) {
        const vector<int> p2{points[j]};
        if (p1 == p2)
          ++samePoints;
        else
          maxPoints = max(maxPoints, ++slopeCount[getSlope(p1, p2)]);
      }
      ans = max(ans, samePoints + maxPoints);
    }

    return ans;
  }

 private:
  pair<int, int> getSlope(const vector<int>& p, const vector<int>& q) {
    const int dx = p[0] - q[0];
    const int dy = p[1] - q[1];
    if (dx == 0)
      return {0, p[0]};
    if (dy == 0)
      return {p[1], 0};
    const int d = __gcd(dx, dy);
    return {dx / d, dy / d};
  }

  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};

int main()
{
}