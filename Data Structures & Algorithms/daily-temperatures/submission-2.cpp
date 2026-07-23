class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int, int>> temps;
        int size = temperatures.size();

        vector<int> ret(size, 0);


        for(int i{size - 1}; i >= 0; --i){
            if(temps.empty()){
                temps.push({temperatures[i], i});
                ret[i] = 0;
                continue;
            }
            while(!temps.empty() && temperatures[i] >= temps.top().first){
                temps.pop();
            }
            if(temps.empty()){
                temps.push({temperatures[i], i});
                ret[i] = 0;
            }
            else{
               ret[i] = temps.top().second - i;
               temps.push({temperatures[i], i});
            }

        }
        return ret;
        
    }
};
