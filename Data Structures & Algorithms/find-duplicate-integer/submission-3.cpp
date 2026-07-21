class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int p1 = nums[0];
        int p2 = nums[nums[0]];

        while (true) {

            p1 = nums[p1];
            p2 = nums[nums[p2]];
            if(p1 == p2){
                break;
            }

            
        }
        p1 = 0;
        while(true){
            p1 = nums[p1];
            p2 = nums[p2];
            if(p1 == p2){
                return p1;
            }
        }
        return nums[p2];
    }
};