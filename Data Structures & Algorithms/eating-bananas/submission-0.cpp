class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(), piles.end());


        int left = 1;
        int right = piles.back();

        while(left <= right){

            int mid = left + (right - left) / 2;
            if(canEat(piles, h, mid)){
                right = mid - 1;
            }
            else if(!canEat(piles, h, mid)){
                left = mid + 1;
            }
        }
        return left;

    }

    bool canEat(vector<int> piles, int h, int num){
        long long hours{};
        for(int i{}; i < piles.size(); ++i){
            hours += (piles[i] + num - 1) / num;

            if(hours > h){
                return false;
            }
        }
        return true;

    }
};
