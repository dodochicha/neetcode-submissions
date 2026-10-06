class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, bool> c;
        int start = 0;
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (c[s[i] - 'a']) {
                while (s[start] != s[i]) {
                    c[s[start] - 'a'] = false;
                    start++;
                    cur--;
                }
                start++;
                c[s[i] - 'a'] = true;
            }
            else {
                c[s[i] - 'a'] = true;
                cur++;
            }
            ans = max(ans, cur);
        }
        return ans;

    }
};
