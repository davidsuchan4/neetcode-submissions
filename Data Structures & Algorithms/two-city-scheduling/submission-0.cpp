class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int total{};
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) > (b[0] - b[1]);
        });
        for (int i{}; i < costs.size(); ++i) {
            if (i < costs.size() / 2) {
                total += costs[i][1];
            } else {
                total += costs[i][0];
            }
        }
        return total;
    }
};