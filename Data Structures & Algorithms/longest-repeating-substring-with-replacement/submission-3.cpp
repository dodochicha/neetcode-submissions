class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int start = 0;
            int end = -1;
            int diff = 0;
            for (int j = 0; j < s.size(); j++) {
                end++;
                if (s[j] - 'A' != i) {
                    diff++;
                }
                while (diff > k) {
                    diff -= (s[start] - 'A' != i);
                    start++;
                }
                ans = max(ans, end - start + 1);
            }
        }
        return ans;
    }
};
