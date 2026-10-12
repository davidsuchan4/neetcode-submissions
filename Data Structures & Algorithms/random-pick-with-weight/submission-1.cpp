class Solution {
public:
    vector<int> w;
    int sum;
    Solution(vector<int>& w) {
        this->w = w;
        this->sum = accumulate(w.begin(), w.end(), 0);

    }
    
    int pickIndex() {
        double target = sum * ((double) rand() / RAND_MAX);
        int curSum = 0;
        for(int i{}; i < w.size(); ++i){
            curSum += w[i];
            if(curSum > target){
                return i;
            }
        }
        return -1;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */