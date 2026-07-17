class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums, 0, 0, dp);
    }

    int dfs(vector<int>& nums, int sum, int index, vector<int>& dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int maximum;

        maximum = max(nums[index] + dfs(nums, sum, index + 2, dp), dfs(nums, sum, index + 1, dp));
        
        return dp[index] = maximum;
    }
};