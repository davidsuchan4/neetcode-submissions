class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        return dfs(piles, 0, 0, piles.size() - 1, 0, true, dp);
    }

    bool dfs(vector<int>& stones, int bob, int alice, int r, int l, bool turn, vector<vector<int>>& dp){
        if(l > r){
            if(bob > alice){
                return false;
            }
            return true;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        if(turn){
            return dp[l][r] = max(dfs(stones, bob, alice + stones[l], r, l + 1, false, dp),
             dfs(stones, bob, alice + stones[r], r - 1, l, false, dp));
        }
        else{
            return dp[l][r] =  max(dfs(stones, bob + stones[l], alice, r, l + 1, true, dp),
             dfs(stones, bob + stones[r], alice, r - 1, l, true, dp));
        }
    }
};