class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int p1{};
        int p2{};
        int maximum = INT_MIN;
        int cur{};

        while(p2 < nums.size()){
            if(cur < 0){
                cur -= nums[p1];
                ++p1;
            }
            else{
                cur += nums[p2];
                ++p2;
                maximum = max(maximum, cur);
            }
        }
        return maximum;
    }
};
