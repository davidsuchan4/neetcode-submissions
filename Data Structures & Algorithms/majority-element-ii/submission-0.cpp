class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int target = nums.size() / 3 + 1;

        for(int i{}; i < nums.size(); ++i){
            ++mp[nums[i]];
        }
        vector<int> ret;
        for(auto& [key, value] : mp){
            if(mp[key] >= target){
                ret.push_back(key);
            }
        }
        return ret;
    }
};