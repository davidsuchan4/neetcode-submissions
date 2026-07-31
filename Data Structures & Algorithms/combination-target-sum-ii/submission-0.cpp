class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, current, result);

        return result;
    }

private:
    void dfs(const vector<int>& candidates,
             int remaining,
             int start,
             vector<int>& current,
             vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicate sibling choices.
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Sorting makes further candidates too large as well.
            if (candidates[i] > remaining) {
                break;
            }

            current.push_back(candidates[i]);

            // Use i + 1 because an element cannot be reused.
            dfs(candidates, remaining - candidates[i],
                i + 1, current, result);

            current.pop_back();
        }
    }
};