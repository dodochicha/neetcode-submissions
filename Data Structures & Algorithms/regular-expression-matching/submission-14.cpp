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
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j < n; j++) {
            if (p[j] == '*') {
                dp[j+1] = dp[j-1];
            }
        }
        for (int i = 0; i < m; i++) {
            bool pre = dp[0];
            dp[0] = false;
            for (int j = 0; j < n; j++) {
                bool tmp = dp[j+1];
                if (p[j] == '.') {
                    dp[j+1] = pre;
                }
                else if (p[j] == '*') {
                    dp[j+1] = dp[j+1] && match(s[i], p[j-1]) || dp[j-1];
                }
                else {
                    dp[j+1] = pre && match(s[i], p[j]);
                }
                pre = tmp;
            }
        }
        return dp[n];
    }
};
