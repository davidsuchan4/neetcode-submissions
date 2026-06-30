class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(grid, dp, 0, 0);

    }

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col){
        cout << row << " " << col << "\n";
        if(row == grid.size() - 1 && col == grid[0].size() - 1){
            return grid[row][col];
        }
        if(row >= grid.size() || col >= grid[0].size()){
            return 10000;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int ways = min(dfs(grid, dp, row + 1, col), dfs(grid, dp, row, col + 1));

        return dp[row][col] = ways + grid[row][col];

    }
};