class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = dfs(coins, amount, dp);
        return (ans > 100000) ? -1 : ans;
    }

    int dfs(vector<int>& coins, int amount, vector<int>& dp){
        if(amount < 0){
            return 100000;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        if(amount == 0){
            return 0;
        }

        int minimum = INT_MAX;
        for(int i{}; i < coins.size(); ++i){
            minimum = min(minimum, dfs(coins, amount - coins[i], dp));
        }

        return dp[amount] = 1 + minimum;
    }
};
