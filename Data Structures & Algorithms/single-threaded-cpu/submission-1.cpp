class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int size = tasks.size();
        vector<vector<int>> indexedTasks(size);
        for (int j = 0; j < size; ++j) indexedTasks[j] = {tasks[j][0], tasks[j][1], j};
        sort(indexedTasks.begin(), indexedTasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int i{0};
        int reti{};
        long long time{0};
        vector<int> ret(size);
        while (reti < size) {
            if (pq.empty() && i < size && time < indexedTasks[i][0]) {
                time = indexedTasks[i][0];
            }
            while (i < size && indexedTasks[i][0] <= time) {
                pq.push({indexedTasks[i][1], indexedTasks[i][2]});
                ++i;
            }
            if (!pq.empty()) {
                ret[reti] = pq.top()[1];
                time += pq.top()[0];
                pq.pop();
                ++reti;
            }
        }
        return ret;
    }
};