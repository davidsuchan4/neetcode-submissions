class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        return dfs(amount, coins, dp, 0);
    }

    int dfs(int amount, vector<int>& coins, vector<vector<int>>& dp, int index){
        if(amount < 0){
            return 0;
        }
        if(index >= coins.size()){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(dp[amount][index] != -1){
            return dp[amount][index];
        }



        int ways{};
        for(int i{index}; i < coins.size(); ++i){
            ways += dfs(amount - coins[i], coins, dp, i);
        }

        return dp[amount][index] = ways;

        
    }
};
