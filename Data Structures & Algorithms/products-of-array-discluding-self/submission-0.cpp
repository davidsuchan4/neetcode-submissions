class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int size = nums.size();
        vector<int> ret(size, 1);
        for(int i{}; i < size; ++i){
            for(int w{}; w < size; ++w){
                if(w == i){
                    continue;
                }
                else{
                    ret[w] *= nums[i];
                }
            }
        }
        return ret;

    }
};
