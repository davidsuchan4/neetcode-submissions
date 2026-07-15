class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for (int i{}; i < position.size(); ++i) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end());

        stack<double> st;

        for(int i = pairs.size() - 1; i >= 0; --i){
            double time = (double)(target - pairs[i].first) / pairs[i].second;
            if(st.empty()){
                st.push(time);
            }
            else{
                if(time <= st.top()){
                    continue;
                }
                else{
                    st.push(time);
                }
            }
        }
        return st.size();

    }
};