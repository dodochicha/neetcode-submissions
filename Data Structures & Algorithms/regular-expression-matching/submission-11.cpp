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
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j < n; j++) {
            if (p[j] == '*') {
                dp[0][j+1] = dp[0][j-1];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[j] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                }
                else if (p[j] == '*') {
                    dp[i+1][j+1] = dp[i][j+1] && match(s[i], p[j-1]) || dp[i+1][j-1];
                }
                else {
                    dp[i+1][j+1] = dp[i][j] && match(s[i], p[j]);
                }
            }
        }
        return dp[m][n];
    }
};
