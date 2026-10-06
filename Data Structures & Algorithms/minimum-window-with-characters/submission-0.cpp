class Solution {
public:
    string minWindow(string s, string t) {
        int j = 0;
        string ans = "";
        unordered_map<char, int> cnt;
        int pos = 0;
        int shortest = INT_MAX;
        for (int i = 0; i < t.size(); i++) {
            pos += (cnt[t[i]] == 0);
            cnt[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            pos -= (cnt[s[i]] == 1);
            cnt[s[i]]--;
            while (j <= i && pos == 0) {
                if (i - j + 1 < shortest) {
                    ans = s.substr(j, i - j + 1);
                    shortest = i - j + 1;
                }
                pos += (cnt[s[j]] == 0);
                cnt[s[j]]++;
                j++;
            }
        }
        return ans;
    }
};
