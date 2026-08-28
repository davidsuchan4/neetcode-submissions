class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) return 1;
        string prev = "";

        int p1 = 0;
        int p2 = 0;
        int maxLen = 1;

        while (p2 < arr.size() - 1) {
            if (arr[p2] < arr[p2 + 1] && (prev == ">" || prev == "")) {
                prev = "<";
                ++p2;
                maxLen = max(maxLen, p2 - p1 + 1);
            } else if (arr[p2] > arr[p2 + 1] && (prev == "<" || prev == "")) {
                prev = ">";
                ++p2;
                maxLen = max(maxLen, p2 - p1 + 1);
            } else {
                if (arr[p2] == arr[p2 + 1]) {
                    p2++;
                    p1 = p2;
                } else {
                    p1 = p2;
                }
                prev = "";
            }
        }
        return maxLen;
    }
};