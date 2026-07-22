class Solution {
   public:
    string decodeString(string s) {
        string res{};
        int i = 0;
        dfs(1, s, i, res);
        return res;
    }

    void dfs(int multiple, const string& str, int& s, string& res){
        for (int i{}; i < multiple; ++i) {
            int temp_s = s;
            while (temp_s < str.size() && str[temp_s] != ']') {
                if (isdigit(str[temp_s])) {
                    int num = 0;
                    while (isdigit(str[temp_s])) num = num * 10 + (str[temp_s++] - '0');
                    temp_s++; // skip [
                    dfs(num, str, temp_s, res);
                    temp_s++; // skip ]
                } else if (str[temp_s] >= 'a' && str[temp_s] <= 'z') {
                    res += str[temp_s++];
                }
            }
            if (i < multiple - 1) temp_s = s; else s = temp_s;
        }
    }
};