class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        queue<int> q;
        for(int i{}; i < nums.size(); ++i){
            q.push(nums[i]);
        }
        int ret{};
        while(!q.empty()){
            vector<int> temp{};
            temp.push_back(q.front());
            q.pop();
            while(!q.empty() && q.front() == temp.back()){
                temp.push_back(q.front());
                q.pop();
            }
            if(temp.size() < 2){
                return -1;
            }
            ret += (temp.size() + 2) / 3;
            

        }
        return ret;
        

    }
};