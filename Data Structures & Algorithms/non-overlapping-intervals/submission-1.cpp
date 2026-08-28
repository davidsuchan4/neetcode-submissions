class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
});
        int cur = intervals[0][1];
        int ret{};
        for (int i{1}; i < intervals.size(); ++i) {
            if (intervals[i][0] < cur) {
                ++ret;
            } else {
                cur = intervals[i][1];
            }
        }
        return ret;
    }
};
