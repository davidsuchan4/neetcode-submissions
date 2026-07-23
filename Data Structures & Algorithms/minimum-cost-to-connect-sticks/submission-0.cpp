class Solution {
public:
    int connectSticks(vector<int>& sticks) {
       priority_queue<int, vector<int>, greater<>> pq;
       int cost{};
       for(int i{}; i < sticks.size(); ++i){
        pq.push(sticks[i]);
       }
       while(!pq.empty()){
        int first = pq.top();
        pq.pop();
        if(pq.empty()){
            break;
        }
        int second = pq.top();
        pq.pop();

        int temp = first + second;
        cost += temp;
        pq.push(temp);
       }
       return cost;
    }
};
