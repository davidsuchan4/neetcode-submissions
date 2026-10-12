class Solution {
   public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        for (int r{}; r < wall.size(); ++r) {
            int interval{};
            for (int c{}; c < wall[r].size() - 1; ++c) {
                interval += wall[r][c];
                edges[interval] += 1;
                
                
            }
        }
        int mostEdges{};
        for(auto& [key, value] : edges){
            mostEdges = max(mostEdges, value);
        }
        return wall.size() - mostEdges;
    }
};