class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            int low = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (low == dp.size()) {
                dp.push_back(nums[i]);
            }
            else {
                dp[low] = nums[i];
            }
        }
        return dp.size();
    }
};
