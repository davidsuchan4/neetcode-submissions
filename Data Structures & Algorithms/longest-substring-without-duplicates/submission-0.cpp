class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left{};
        int right{};
        unordered_map<char, int> mp;
        int maxlen{};
        int count{};

        while(right < s.size()){
            if(mp[s[right]] > 0){
                while(s[left] != s[right]){
                    --mp[s[left]];
                    ++left;
                    --count;
                }
                --mp[s[left]];
                ++left;
                --count;
            }
            else{
                ++mp[s[right]];
                ++count;
                ++right;
                maxlen = max(maxlen, count);
            }
        }
        return maxlen;
    }
};
