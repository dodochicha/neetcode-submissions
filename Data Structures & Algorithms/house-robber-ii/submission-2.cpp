class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        ans = dp[0];
        if (n >= 2) {
            dp[1] = nums[0];
            ans = max(ans, nums[1]);
        }
        if (n >= 3) {
            for (int i = 2; i < n - 1; i++) {
                dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            }
            ans = dp[n-2];
            dp.assign(n, 0);
            dp[0] = 0;
            dp[1] = nums[1];
            for (int i = 2; i < n; i++) {
                dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            }
            ans = max(ans, dp[n-1]);
        }
        return ans;
    }
};
