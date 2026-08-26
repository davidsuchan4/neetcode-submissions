class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> locs;
        int size = s.size();
        for (int i{size - 1}; i >= 0; --i) {
            if(locs.find(s[i]) == locs.end()){
                locs[s[i]] = i;
            }
        }
        int p1{0};
        vector<int> ret;
        while(p1 < size){
            int start = p1;
            int cur = locs[s[p1]];
            while(p1 <= cur){
                cur = max(cur, locs[s[p1]]);
                p1++;
            }
            ret.push_back(p1 - start);
        }
        return ret;
    }
};