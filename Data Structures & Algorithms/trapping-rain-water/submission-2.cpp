class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int ans = 0;
        int l = 0;
        int r = n - 1;
        int maxL = height[0];
        int maxR = height[n-1];
        while (l < r) {
            if (maxL < maxR) {
                ans += max(0, maxL - height[l]);
                l++;
                maxL = max(maxL, height[l]);
            }
            else {
                ans += max(0, maxR - height[r]);
                r--;
                maxR = max(maxR, height[r]);
            }
        }
        return ans;
    }
};
