class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1{};
        int p2 = heights.size() - 1;
        int maximum = {};
        while(p1 < p2){
            int area = min(heights[p1], heights[p2]) * (p2 - p1);
            maximum = max(maximum, area);
            if(heights[p1] < heights[p2]){
                ++p1;
            }
            else{
                --p2;
            }
        }
        return maximum;
    }
};