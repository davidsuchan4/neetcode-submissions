class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        dfs(nums, {}, ret, 0);
        return ret;
    }

    void dfs(vector<int>& nums, vector<int> cur, vector<vector<int>>& ret, int index) {
        ret.push_back(cur);

        if (index >= nums.size()) {
            return;
        }

        for(int i{index}; i < nums.size(); ++i){
            if(i > index){
                if(nums[i] == nums[i - 1]){
                    continue;
                }
            }
            cur.push_back(nums[i]);
            dfs(nums, cur, ret, i + 1);
            cur.pop_back();
        }
        
    }
};
