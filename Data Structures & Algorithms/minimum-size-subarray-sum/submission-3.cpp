class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left{};
        int right{1};
        int ret{INT_MAX};
        int sum{nums[0]};

        while(left < nums.size()){
            if(sum < target){
                if(right >= nums.size()){
                    break;
                }
                sum += nums[right];
                ++right;
            }
            else{
                ret = min(ret, right - left);
                sum -= nums[left];
                ++left;
            }


        }

        if(ret == INT_MAX){
            return 0;
        }
        return ret;
    }
};