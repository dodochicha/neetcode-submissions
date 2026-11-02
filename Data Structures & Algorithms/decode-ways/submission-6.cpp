class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        if (n == 1) return (s[0] - '0' > 0) ? 1 : 0;
        int prev1 = 0;
        int prev2 = (n >= 2 && s[0] - '0' > 0) ? 1 : 0;
        if (prev2 == 0) return 0;
        int cur = prev2;
        if (n >= 2) {
            int num = (s[0] - '0') * 10 + (s[1] - '0');
            if (num <= 26 && num >= 10) {
                prev1 = (s[1] - '0' == 0) ? 1 : 2;
            }
            else if (s[1] - '0' == 0) {
                return 0;
            }
            else {
                prev1 = 1;
            }
            cur = prev1;
        }
        for (int i = 2; i < n; i++) {
            int num = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (num <= 26 && num >= 10) {
                cur = (s[i] - '0' == 0) ? prev2 : prev2 + prev1;
            }
            else if (s[i] - '0' == 0) {
                cur = 0;
            }
            else {
                cur = prev1;
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};
