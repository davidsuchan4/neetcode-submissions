class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        dfs(n, k, 0, {}, ret);
        return ret;

        
    }

    void dfs(int n, int k, int cur, vector<int> temp,vector<vector<int>>& ret){
        if(cur > n){
            return;
        }
        if(temp.size() == k){
            ret.push_back(temp);
            return;
        }

        for(int i{cur + 1}; i <= n; ++i){
            cout << 'a';
            temp.push_back(i);
            dfs(n, k, i, temp, ret);
            temp.pop_back();
        }
        
    }
};