class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int size = weights.size();
        int max{};
        for(int i{}; i < size; ++i){
            max += weights[i];
        }
        int left = 1;
        int right = max;
        int mid;
        int ans = max;

        while(left <= right){
            mid = left + (right - left) / 2;
            bool res = calculate(weights, days, mid);
            if(res){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;



    }

    bool calculate(vector<int>& weights, int days, int target){
        int cur{};
        int ret{1};

        for(int i{}; i < weights.size(); ++i){
            if(target < weights[i]){
                return false;
            }
            if(cur + weights[i] > target){
                ++ret;
                cur = weights[i];
            }
            else{
                cur += weights[i];
            }
        }

        if(ret <= days){
            return true;
        }
        return false;
    }
};