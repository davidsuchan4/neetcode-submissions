class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> storage(3, 0);
        for(int i{}; i < nums.size(); ++i){
            ++storage[nums[i]];
        }
        int idx{};
        for(int i{}; i < 3; ++i){
            for(int w{0}; w < storage[i]; ++w){
                nums[idx] = i;
                ++idx;
            }
        }
        
    }
};