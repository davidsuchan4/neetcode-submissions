class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int rsize = grid.size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int csize = grid[0].size();
        int count{};
        for (int r{}; r < rsize; ++r) {
            for (int c{}; c < csize; ++c) {
                if (grid[r][c] == '1') {
                    queue<vector<int>> bfs;
                    bfs.push({r, c});
                    grid[r][c] = '0';
                    while (!bfs.empty()) {
                        vector<int> coord = bfs.front();
                        bfs.pop();
                        for (int i{}; i < 4; ++i) {
                            int nr = coord[0] + dirs[i][0];
                            int nc = coord[1] + dirs[i][1];
                            if (nr >= 0 && nr < rsize && nc >= 0 && nc < csize && grid[nr][nc] == '1') {
                                grid[nr][nc] = '0';
                                bfs.push({nr, nc});
                            }
                        }
                    }
                    ++count;
                }
            }
        }
        return count;
    }
};