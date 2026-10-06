class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int start = 0;
        int maxCount = 0;
        unordered_map<char, int> dict;
        for (int i = 0; i < s.size(); i++) {
            dict[s[i]-'A']++;
            maxCount = max(maxCount, dict[s[i]-'A']);
            if (i - start + 1 - maxCount > k) {
                dict[s[start]-'A']--;
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
