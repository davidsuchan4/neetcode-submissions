class Solution {
   public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int dominant{};
        for (int i{}; i < nums.size(); ++i) {
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 1;

            } else {
                ++freq[nums[i]];
            }
            dominant = (freq[nums[i]] > freq[dominant]) ? nums[i] : dominant;
        }
        int size = nums.size();
        int counter{};
        for (int i{}; i < nums.size(); ++i) {
            if (nums[i] == dominant) {
                ++counter;
            }
            int currentSize = i + 1;
            int otherHalf = freq[dominant] - counter;
            if (currentSize / 2 < counter && (size - currentSize) / 2 < otherHalf) {
                return i;
            }
        }
        return -1;
    }
};