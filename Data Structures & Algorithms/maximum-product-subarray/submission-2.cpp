class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int prefix{};
        int suffix{};
        int ret{nums[0]};
        
        int current{1};
        for(int i{}; i < size; ++i){
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);
            suffix = nums[size - 1 - i] * (suffix == 0 ? 1 : suffix);
            ret = max(ret, max(prefix, suffix));
        }
        return ret;

    }
};
