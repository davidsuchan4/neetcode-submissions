class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);

        return dfs(nums, target, dp);
    }


    int dfs(vector<int>& nums, int target, vector<int>& dp){
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[target] != -1){
            return dp[target];  
        }

        int ways{};
        for(int i{}; i < nums.size(); ++i){
            ways += dfs(nums, target - nums[i], dp);
        }
        return dp[target] = ways;
    }
};