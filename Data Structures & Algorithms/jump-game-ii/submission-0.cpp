class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums, dp, 0);
    }

    int dfs(vector<int>& nums, vector<int>& dp, int index){
        if(index >= nums.size() - 1){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }
        int minimum = INT_MAX;
        for(int i{1}; i <= nums[index]; ++i){
            if(i + index >= nums.size()){
                break;
            }
            
            int result = dfs(nums, dp, index + i);
            if(result != INT_MAX){
                minimum = min(minimum, 1 + result);
            }

        }
        return dp[index] = minimum;
    }
};
