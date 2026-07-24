class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rsize = grid.size();
        if (rsize == 0) return;
        int csize = grid[0].size();
        queue<vector<int>> bfs;
        for (int r{}; r < rsize; ++r) {
            for (int c{}; c < csize; ++c) {
                if(grid[r][c] == 0){
                    bfs.push({r,c});
                }
            }
        }

        vector<vector<int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0, -1}
        };
        int steps{1};
        while(!bfs.empty()){
            int size = bfs.size();
            for(int s{}; s < size; ++s){
                vector<int> front = bfs.front();
                bfs.pop();
                for(int i{}; i < 4; ++i){
                    int nr = front[0] + dirs[i][0];
                    int nc = front[1] + dirs[i][1];
                    if(nr >= 0 && nr < rsize && nc >= 0 && nc < csize && grid[nr][nc] == 2147483647){
                        grid[nr][nc] = steps;
                        bfs.push({nr, nc});
                    }
                }
            }
            ++steps;
        }
    }
};