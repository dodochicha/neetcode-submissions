#include <array>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::array<int, 26>, int> dict;
        int num_group = 0;
        vector<vector<string>> ans = {};
        for (int i = 0; i < strs.size(); i++) {
            std::array<int, 26> cnt = {0};
            for (char &l: strs[i]) {
                cnt[l - 'a']++;
            }
            auto it = dict.find(cnt);
            if (it != dict.end()) {
                ans[dict[cnt]].push_back(strs[i]);
            }
            else {
                ans.push_back({strs[i]});
                dict[cnt] = num_group++;
            }
        }
        return ans;
    }
};
