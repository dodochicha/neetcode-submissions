class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int curMax = 0;
        for (int i = 0; i < n; i++) {
            if (i > curMax) return false;
            curMax = max(curMax, i + nums[i]);
        }
        return (curMax >= n - 1);
    }
};
