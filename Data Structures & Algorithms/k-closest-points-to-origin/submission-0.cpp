  class Solution {
  public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          priority_queue<
              vector<int>,
              vector<vector<int>>,
              greater<vector<int>>
          > pq;

          for (int i = 0; i < points.size(); ++i) {
              int x = points[i][0];
              int y = points[i][1];
              int dist = x * x + y * y;

              pq.push({dist, x, y});
          }

          vector<vector<int>> ret;

          for (int i = 0; i < k; ++i) {
              vector<int> top = pq.top();
              pq.pop();

              ret.push_back({top[1], top[2]});
          }

          return ret;
      }
  };