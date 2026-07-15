class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> base;
        unordered_map<char, int> cmp;
        for(int i{}; i < s1.size(); ++i){
            ++base[s1[i]];
            ++cmp[s2[i]];
        }
        
        int left{};
        int right = s1.size();

        while(right < s2.size()){
            if(base == cmp) return true;
            if(--cmp[s2[left]] == 0){
                cmp.erase(s2[left]);
            }
            left++;
            ++cmp[s2[right]];
            right++;

        }
        return base == cmp;     
        
    }
};