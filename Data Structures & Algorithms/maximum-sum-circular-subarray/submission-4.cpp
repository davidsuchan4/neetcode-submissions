class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int size = nums.size();
        vector<int> rightMax(size);
        int suffixSum = nums[size - 1];
        rightMax[size - 1] = nums[size - 1];
        for(int i{size - 2}; i >= 0; --i){
            suffixSum += nums[i];
            rightMax[i] = max(suffixSum, rightMax[i + 1]);
        }
        int maxSum = nums[0];
        int curMax = 0;
        int prefixSum = 0;

        for(int i{}; i < size; ++i){
            curMax = max(curMax, 0) + nums[i];
            maxSum = max(maxSum, curMax);
            prefixSum += nums[i];
            if(i + 1 < size){
                maxSum = max(maxSum, prefixSum + rightMax[i + 1]);
            }
        }
        return maxSum;


        
    }
};