class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = (sum + 1) / 2;
        vector<vector<int>> dp(stones.size() + 1, vector<int>(target + 1, -1));
        return dfs(0, 0, stones, target, sum, dp);

        
    }

    int dfs(int index, int sum, vector<int>& stones, int target, int total, vector<vector<int>>& dp){
        if(sum >= target || index >= stones.size()){
            return abs(total - 2 * sum);        
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        return dp[index][sum] = min(
            dfs(index + 1, sum + stones[index], stones, target, total, dp),
            dfs(index + 1, sum, stones, target, total, dp)
        );
    }
};