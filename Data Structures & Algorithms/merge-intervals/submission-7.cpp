class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        for(int i{}; i < intervals.size(); ++i){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i + 1 < intervals.size() && intervals[i + 1][0] <= end){
                if(intervals[i + 1][1] >= end){
                    end = intervals[i + 1][1];
                }
                ++i;
            }
            ret.push_back({start, end});


        }
        return ret;

    }
};