class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left{};
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;

            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                int p1{mid};
                int p2{mid};
                while (
                    (p1 + 1 < nums.size() && nums[p1 + 1] == target) ||
                    (p2 - 1 >= 0 && nums[p2 - 1] == target)
                ) {
                    if (p1 + 1 < nums.size() && nums[p1 + 1] == target) {
                        ++p1;
                    }

                    if (p2 - 1 >= 0 && nums[p2 - 1] == target) {
                        --p2;
                    }
                }
                return {p2, p1};
            }
        }
        return {-1, -1};
    }
};