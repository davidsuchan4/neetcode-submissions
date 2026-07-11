class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ret(size);

        for(int i{size - 1}; i >= 0; --i){
            if(st.empty()){
                st.push({temperatures[i], i});
            }
            else{
                while(!st.empty() && st.top().first <= temperatures[i]){
                    cout << st.top().first  << " " << temperatures[i] << ' ' << i << "\n";
                    st.pop();
                }
                if(st.empty()){
                    cout << 'a' << '\n';
                    st.push({temperatures[i], i});
                }
                else{
                    ret[i] = st.top().second - i;
                    st.push({temperatures[i], i});
                }
            }
            
        }
        return ret;
    }
};
