class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> countGap;
        countGap[0] = 0;

        for (const auto& row : wall) {
            int total = 0;
            for (size_t i = 0; i < row.size() - 1; ++i) {
                total += row[i];
                countGap[total]++;
            }
        }

        int maxGaps = 0;
        for (const auto& [key, value] : countGap) {
            maxGaps = max(maxGaps, value);
        }

        return wall.size() - maxGaps;
    }
};