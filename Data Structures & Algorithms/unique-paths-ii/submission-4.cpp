class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1){
            return 0;
        }
        return dfs(obstacleGrid, 0, 0, dp);
    }

    int dfs(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>>& dp){
        if(row >= obstacleGrid.size() || col >= obstacleGrid[0].size()){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        if(row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1){
            return 1;
        }
        int paths{};
        if(row + 1 < obstacleGrid.size() && obstacleGrid[row + 1][col] != 1){
            paths += dfs(obstacleGrid, row + 1, col, dp);
        }
        if(col + 1 < obstacleGrid[0].size() && obstacleGrid[row][col + 1] != 1){
            paths += dfs(obstacleGrid, row, col + 1, dp);
        }

        return dp[row][col] = paths;

    }
};