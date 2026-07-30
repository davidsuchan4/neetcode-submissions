class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        dfs(nums, 0, target, {}, ret);
        return ret;
        
    }

    void dfs(vector<int>& nums, int index, int target, vector<int> cur, vector<vector<int>>& ret){
        if(target == 0){
            ret.push_back(cur);
            return;
        }
        if(index >= nums.size() || target < 0){
            return;
        }

        cur.push_back(nums[index]);
        // The same number may be chosen an unlimited number of times,
        // so we stay at the same index for the recursive call.
        dfs(nums, index, target - nums[index], cur, ret);
        
        cur.pop_back();
        // Move to the next index to explore combinations without the current number.
        dfs(nums, index + 1, target, cur, ret);
    }
};