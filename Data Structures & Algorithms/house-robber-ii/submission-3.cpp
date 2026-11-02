class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        if (n == 1) return nums[0];
        auto solve = [&](int l, int r) {
            if (r < l) return 0;
            int prev1 = 0;
            int prev2 = 0;
            int cur = nums[0];
            for (int i = l; i <= r; i++) {
                cur = max(prev2 + nums[i], prev1);
                prev2 = prev1;
                prev1 = cur;
            }
            return cur;
        };
        return max(solve(0, n-2), solve(1, n-1));
    }
};
