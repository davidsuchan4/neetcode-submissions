class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left{};
        int right{1};
        int ret{1};
        int inc = k;
        sort(nums.begin(), nums.end());
        long long current{nums[0]};
        while(right < nums.size()){
            long long target = (right - left) * nums[right];
            if(k >= target - current){
                current += nums[right];
                ret = max(ret, right - left + 1);
                ++right;

            }
            else{
                current -= nums[left];
                ++left;
            }
        }
        return ret;
    }
};