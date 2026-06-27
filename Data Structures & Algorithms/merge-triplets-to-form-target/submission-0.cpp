class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool can1 = false;
        bool can2 = false;
        bool can3 = false;
        for(int i{}; i < triplets.size(); ++i){
            if(triplets[i][0]== target[0]){
                if(target[1] >= triplets[i][1] && target[2] >= triplets[i][2]){
                    can1 = true;
                }
            }
            if(triplets[i][1]== target[1]){
                if(target[0] >= triplets[i][0] && target[2] >= triplets[i][2]){
                    can2 = true;
                }
            }
            if(triplets[i][2]== target[2]){
                if(target[1] >= triplets[i][1] && target[0] >= triplets[i][0]){
                    can3 = true;
                }
            }
        }
        return(can1 && can2 && can3);

    }
};
