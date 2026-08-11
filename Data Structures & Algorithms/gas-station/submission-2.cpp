class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(cost.begin(), cost.end(), 0) > accumulate(gas.begin(), gas.end(), 0)) {
            return -1;
        }
        int tank{};
        int start = 0;
        for(int i{}; i < gas.size(); ++i){
            tank += gas[i];
            tank -= cost[i];
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
};