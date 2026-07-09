class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ret;

        for(int i{}; i < strs.size(); ++i){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(strs[i]);
        }

        for(auto& [key, value] : mp){
            vector<string> temp;
            for(int i{}; i < value.size(); ++i){
                temp.push_back(value[i]);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};