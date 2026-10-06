class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (n > 1 && p[1] == '*') {
                    if (p[i] == '.') {
                        for (int j = 0; j < m; j++) {
                            dp[i+1][j+1] = true;
                        }
                    }
                    else {
                        dp[1][1] = true;
                        for (int j = 1; j < m; j++) {
                            dp[i+1][j+1] = dp[i+1][j] && (s[j] == p[i]);
                        }
                    }
                }
                else if (p[i] == '.') {
                    dp[1][1] = true;
                }
                else {
                    dp[1][1] = (s[0] == p[i]);
                }
            }
            else {
                if (i < n - 1 && p[i+1] == '*') {
                    if (p[i] == '.') {
                        for (int j = 0; j < m; j++) {
                            dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
                        }
                    }
                    else {
                        for (int j = 0; j < m; j++) {
                            dp[i+1][j+1] = dp[i][j+1] || (dp[i][j] || dp[i+1][j]) && (s[j] == p[i]);
                        }
                    }
                }
                else if (p[i] == '.') {
                    for (int j = 0; j < m; j++) {
                        dp[i+1][j+1] = dp[i][j];
                    }
                }
                else if (p[i] == '*') {
                    for (int j = 0; j < m; j++) {
                        dp[i+1][j+1] = dp[i][j+1];
                    }
                }
                else {
                    for (int j = 0; j < m; j++) {
                        dp[i+1][j+1] = dp[i][j] && (s[j] == p[i]);
                    }
                }
            }
        }
        return dp[n][m];
    }
};
