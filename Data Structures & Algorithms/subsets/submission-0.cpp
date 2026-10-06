class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        auto dfs = [&] (this auto&& dfs, bool select, int idx) {
            if (idx == nums.size()) {
                if (select) ans.push_back(cur);
                return;
            }
            if (select) cur.push_back(nums[idx]);
            dfs(false, idx + 1);
            dfs(true, idx + 1);
            if (select) cur.pop_back();
        };
        dfs(false, -1);
        return ans;
    }
};
