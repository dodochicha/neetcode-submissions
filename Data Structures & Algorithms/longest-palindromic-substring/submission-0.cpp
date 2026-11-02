class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        int ansl = 0;
        int ansr = 0;
        int ans = 1;
        bool odd = true;
        for (int i = 0; i < n; i++) {
                int j = 1;
                int len = 1;
                while (i - j >= 0 && i + j <= n - 1) {
                    if (s[i-j] == s[i+j]) len += 2;
                    else break;
                    j++;
                }
                j--;
                if (len > ans) {
                    ans = len;
                    ansl = i - j;
                    ansr = i + j;
                }
                len = 0;
                j = 0;
                while (i - j >= 0 && i + j + 1 <= n - 1) {
                    if (s[i-j] == s[i+j+1]) len += 2;
                    else break;
                    j++;
                }
                j--;
                if (len > ans) {
                    ans = len;
                    ansl = i - j;
                    ansr = i + j + 1;
                }
        }
        return s.substr(ansl, ans);
    }
};
