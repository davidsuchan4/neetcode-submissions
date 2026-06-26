class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(nums, ret, {}, {});
        return ret;


    }

    void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<int> temp, set<int> st){
        if(nums.size() <= temp.size()){
            ret.push_back(temp);
        }

        for(int i{}; i < nums.size(); ++i){
            if(!st.count(nums[i])){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                dfs(nums, ret, temp, st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }

    }
};
