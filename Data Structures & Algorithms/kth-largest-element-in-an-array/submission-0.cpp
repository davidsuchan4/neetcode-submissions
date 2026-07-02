class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i{}; i < nums.size(); ++i){
            pq.push(nums[i]);
        }

        for(int i{}; i < k - 1; ++i){
            pq.pop();
        }

        return pq.top();
    }
};
