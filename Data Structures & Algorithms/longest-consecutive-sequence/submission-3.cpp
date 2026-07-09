class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_map<int, int> mp;
        int ret{};

        for(int i{}; i < nums.size(); ++i){
            ++mp[nums[i]];
        }

        for(auto& [key, value] : mp){
            int i{};
            if(!mp.contains(key - 1)){
                while(mp.contains(key + i)){
                    ++i;
                }
                ret = max(ret, i);
            }
        }
        return ret;
    }
};
