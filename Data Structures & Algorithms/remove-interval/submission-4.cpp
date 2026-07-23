class Solution {
   public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int size = intervals.size();
        int first = toBeRemoved[0];
        int second = toBeRemoved[1];
        cout << first;
        cout << second;
        vector<vector<int>> ret;
        int i{};
        while ( i < size && first >= intervals[i][1]) {
            ret.push_back(intervals[i]);
            ++i;
        }

        if (i >= size) {
            return {};
        }

        if (first > intervals[i][0]) {
            ret.push_back({intervals[i][0], first});
        }


        while (i < size && second > intervals[i][0]) {
            if (intervals[i][1] > second) {
                ret.push_back({second, intervals[i][1]});
            }
            ++i;
        }

        while (i < size) {
            ret.push_back(intervals[i]);
            ++i;
        }
        if (ret.empty()) {
            return {};
        }
        return ret;
    }
};
