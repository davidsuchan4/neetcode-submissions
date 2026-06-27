class Solution {

public:

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);

        return dfs(s, dictionary, dp, 0);
    }

    int dfs(string s, vector<string>& dictionary, vector<int>& dp, int index){
        if(index >= s.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int res = 1 + dfs(s, dictionary, dp, index + 1);

        for(string& word : dictionary){
            if(s.substr(index, word.size()) == word){
                res = min(res, dfs(s, dictionary, dp, index + word.size()));
            }
        }

        return dp[index] = res;

    }
};