class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int n = s.size();
        vector<int> minpos(26, INT_MAX);
        vector<int> maxpos(26, -INT_MAX);
        for (int i = 0; i < n; i++) {
            minpos[s[i]-'a'] = min(minpos[s[i]-'a'], i);
            maxpos[s[i]-'a'] = max(maxpos[s[i]-'a'], i);
        }
        int farthest = 0;
        int start = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            farthest = max(farthest, maxpos[s[i]-'a']);
            if (i == farthest) {
                ans.push_back(farthest - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
