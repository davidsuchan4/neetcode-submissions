class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return dfs(n, dp);
    }

    int dfs(int n, vector<int>& dp){
        if(n <= 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int maximum = 0;

        for(int i{1}; i < n; ++i){
            maximum = max(maximum, i * max(n - i, dfs(n - i, dp)));
        }
        return dp[n] = maximum;
    }
};