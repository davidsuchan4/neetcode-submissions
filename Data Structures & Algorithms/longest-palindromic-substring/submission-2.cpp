class Solution {
public:
    string longestPalindrome(string s) {
        string ret{};
        int size = s.size();
        if(size == 1){
            return s;
        }
        for(int i{0}; i < size - 1; ++i){
            int p1{};
            int p2{};
            int len{};

            p1 = i;
            p2 = i + 1;
            while(p1 >= 0 && p2 < size && s[p1] == s[p2]){
                --p1;
                ++p2;
                len += 2;
            }
            ret = (len > ret.size()) ? s.substr(p1 + 1, p2 - p1 - 1) : ret;
        
            len = 0;
            p1 = i - 1;
            p2 = i + 1;
            ++len;
            while(p1 >= 0 && p2 < size && s[p1] == s[p2]){
                --p1;
                ++p2;
                len += 2;
            }
            ret = (len > ret.size()) ? s.substr(p1 + 1, p2 - p1 - 1) : ret;

        }
        return ret;
    }
};
