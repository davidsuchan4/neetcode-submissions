class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int p1{};
        int p2{-1};
        int ones{};
        int maxlen{};
        while (p2 + 1 < nums.size()) {
            ++p2;
            if(nums[p2] == 1){
                ++ones;
            }
            while((p2 - p1 + 1) - ones > k){
                if(nums[p1] == 1){
                    --ones;
                }
                ++p1;
            }
            maxlen = max(maxlen, p2 - p1 + 1);
        }
        return maxlen;
    }
};