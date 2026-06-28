class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        queue<vector<int>> q;
        int ret{};

        int rows = grid.size();
        int cols = grid[0].size();

        for (int r{}; r < rows; ++r) {
            for (int c{}; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    grid[r][c] = 0;

                    int island_size{};

                    while (!q.empty()) {
                        int curr_r = q.front()[0];
                        int curr_c = q.front()[1];
                        q.pop();

                        ++island_size;

                        for (int i{}; i < 4; ++i) {
                            int nr = curr_r + directions[i][0];
                            int nc = curr_c + directions[i][1];

                            if (
                                nr >= 0 && nr < rows &&
                                nc >= 0 && nc < cols &&
                                grid[nr][nc] == 1
                            ) {
                                q.push({nr, nc});
                                grid[nr][nc] = 0;
                            }
                        }
                    }

                    ret = max(ret, island_size);
                }
            }
        }

        return ret;
    }
};