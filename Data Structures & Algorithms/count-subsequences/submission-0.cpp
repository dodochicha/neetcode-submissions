class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.size();
        const int n = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i+1][j+1] = dp[i+1][j] + ((s[j] == t[i]) ? dp[i][j] : 0);
            }
        }
        return dp[n][m];
    }
};
