class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1)) ;
       return dfs(text1, text2, dp, 0, 0);

    }

    int dfs(const string& text1, const string& text2, vector<vector<int>>& dp, int idx1, int idx2){
        if(idx1 >= text1.size() || idx2 >= text2.size()){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }

        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + dfs(text1, text2, dp, idx1 + 1, idx2 + 1);
        }
        return  dp[idx1][idx2] = max(dfs(text1, text2, dp, idx1 + 1, idx2), dfs(text1, text2, dp, idx1 , idx2 + 1));
    }
};
