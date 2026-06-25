class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {

        unordered_map<int, int> newx;
        priority_queue<pair<int, int>> pq;

        for(int i{}; i < x.size(); ++i){

            newx[i] = x[i];
            pq.push({y[i], i});

        }

        int count{3};
        int ret{};
        set<int> seen;
        while(!pq.empty() && count > 0){
            if(seen.count(newx[pq.top().second])){
                pq.pop();
            }
            else{
                ret += pq.top().first;
                seen.insert(newx[pq.top().second]);
                pq.pop();
                --count;
            
            }
        }

        if(count){
            return -1;
        }
        else{
            return ret;
        }


    }
};