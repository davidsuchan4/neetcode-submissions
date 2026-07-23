class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        map<int, int> cardFreq;
        for (int i{}; i < hand.size(); ++i) {
            ++cardFreq[hand[i]];
        }
       int counted{};
        while(counted < hand.size()){
            int smallest = -1;
            for(auto [key, value] : cardFreq){
                if(value > 0){
                    smallest = key;
                    break;
                }
            }
            int cur = smallest;
            for(int i{}; i < groupSize; ++i){
                if(cardFreq[cur] > 0){
                    --cardFreq[cur];
                    cur = cur + 1;
                    ++counted;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};