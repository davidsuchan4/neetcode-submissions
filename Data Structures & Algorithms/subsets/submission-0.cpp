class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        dfs(nums, ret, temp, 0);
        return ret;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<int>& temp, int index){
        if(index >= nums.size()){
            ret.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        dfs(nums, ret, temp, index + 1);
        temp.pop_back();
        dfs(nums, ret, temp, index + 1);
    }
};
