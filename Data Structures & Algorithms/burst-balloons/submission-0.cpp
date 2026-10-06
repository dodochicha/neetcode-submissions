class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        vector<int> val(n + 2, 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        for (int i = 0; i < n; i++) {
            val[i + 1] = nums[i];
        }
        auto solve = [&](this auto&& solve, int i, int j) {
            if (i >= j - 1) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int ans = 0;
            for (int k = i + 1; k < j; k++) {
                ans = max(ans, val[i] * val[k] * val[j] + solve(i, k) + solve(k, j));
            }
            return ans;
        };
        return solve(0, n + 1);
    }
};
