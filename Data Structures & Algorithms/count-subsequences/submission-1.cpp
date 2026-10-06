class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.size();
        const int n = t.size();
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                for (int j = 0; j < m; j++) {
                    dp[j+1] = dp[j] + ((s[j] == t[i]) ? 1 : 0);
                }
            }
            else {
                int pre = dp[0];
                for (int j = 0; j < m; j++) {
                    int tmp = dp[j+1];
                    dp[j+1] = dp[j] + ((s[j] == t[i]) ? pre : 0);
                    pre = tmp;
                }
            }
        }
        return dp[m];
    }
};
