class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int size = people.size();
        int p1{};
        int p2{size - 1};
        int boats{};

        while(p1 <= p2){
            if(people[p1] + people[p2] <= limit){
                ++p1;
                --p2;
                ++boats ;
            }
            else{
                --p2;
                ++boats;
            }
        }
        return boats;
    }
};