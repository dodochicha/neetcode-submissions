class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs.size(); i++) {
            int len = strs[i].size();
            ans += "#";
            ans += to_string(len);
            ans += "#";
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        // return {s};
        vector<string> ans;
        int idx = 0;
        while (idx < s.size()) {
            int len = 0;
            string cur = "";
            if (s[idx] == '#') {
                idx++;
                while (s[idx] != '#') {
                    len *= 10;
                    len += s[idx] - '0';
                    idx++;
                }
            }
            idx++;
            for (int i = 0; i < len; i++) {
                cur += s[idx];
                idx++;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
