class Solution {
   public:
    int maxLength(vector<int>& ribbons, int k) {
        long long total = 0;
        int max_val = 0;
        for (int r : ribbons) {
            total += r;
            max_val = max(max_val, r);
        }
        if(k > total){
            return 0;
        }
        int left{1};
        int right = max_val;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(canCut(ribbons, k, mid)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }

    bool canCut(vector<int>& ribbons, int k, int size) {
        long long count = 0;
        for (int r : ribbons) {
            count += r / size;
        }
        return count >= k;
    }
};