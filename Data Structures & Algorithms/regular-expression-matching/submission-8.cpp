class Solution {
private:
    bool match(char s, char p) {
        if (p == '.') return true;
        else return (s == p);
    }
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < n; i++) {
            if (p[i] == '*') {
                dp[i+1][0] = dp[i-1][0];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                }
                else if (p[i] == '*') {
                    dp[i+1][j+1] = dp[i-1][j+1] || (dp[i+1][j]) && match(s[j], p[i-1]);
                }
                else {
                    dp[i+1][j+1] = dp[i][j] && match(s[j], p[i]);
                }
            }
        }
        return dp[n][m];
    }
};
