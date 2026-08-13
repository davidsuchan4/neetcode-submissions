class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        vector<int> square(4, 0);
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4 != 0){
            return false;
        }
        int side = total / 4;
        sort(matchsticks.begin(), matchsticks.end());
        return dfs(matchsticks, square, 0, side);
        


    }

    bool dfs(vector<int>& matchsticks, vector<int>& square, int index, int side){

        if(index >= matchsticks.size()){
            return true;
        }

        for(int s{}; s < 4; ++s){
            if(square[s] + matchsticks[index] <= side){
                square[s] += matchsticks[index];
                if(dfs(matchsticks, square, index + 1, side)){
                    return true;
                }
                square[s] -= matchsticks[index];
            }
            else if(s == 3){
                return false;
            }
        }
        
        return false;
    }
};