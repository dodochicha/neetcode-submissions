class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int w = 1;
            ans++;
            while (i - w >= 0 && i + w < n) {
                if (s[i-w] == s[i+w]) ans++;
                else break;
                w++;
            }
            w = 0;
            while (i - w >= 0 && i + w + 1 < n) {
                if (s[i-w] == s[i+w+1]) ans++;
                else break;
                w++;
            }
        }
        return ans;
    }
};
