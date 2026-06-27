class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        dfs(s, ret, {}, "", 0);
        return ret;
    }

    void dfs(string s, vector<vector<string>>& ret, vector<string> temparr, string tempstr, int index){

        if(index >= s.size()){
            if(!temparr.empty() && tempstr == ""){
                ret.push_back(temparr);
                
            }
            return;
        }
        tempstr += s[index];
        dfs(s, ret, temparr, tempstr, index + 1);

        string newstr = tempstr;
        reverse(tempstr.begin(), tempstr.end());
        if(tempstr == newstr){
            if(tempstr != ""){
                temparr.push_back(tempstr);
                dfs(s, ret, temparr, "", index + 1);
            }
        }

    }
};
