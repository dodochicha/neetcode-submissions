class Solution {
public:
    int maxArea(vector<int>& heights) {
        int r = heights.size() - 1;
        int l = 0;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) l++;
            else r--; 
        }

        return ans;
    }
};
