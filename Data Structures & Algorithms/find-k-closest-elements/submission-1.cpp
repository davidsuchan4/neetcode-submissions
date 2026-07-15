class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left{};
        int right{k};
        int retl;
        int retr;
        int diff{};
        int cur{};
        for (int i{}; i < k; ++i) {
            cur += abs(x - arr[i]);
        }
        diff = cur;
        retl = left;
        retr = right;
        while(right < arr.size()){
            cur -= abs(x - arr[left]);
            ++left;
            cur += abs(x - arr[right]);
            ++right;
            if(cur < diff){
                diff = cur;
                retl = left;
                retr = right;
            }


        }
        vector<int> ret(arr.begin() + retl, arr.begin() + retr);
        return ret;
    }
};