class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int right = 0;
        int left = 0;
        int ans = 0;
        while (right < n - 1) {
            int farthest = 0;
            for (int i = left; i <= right; i++) {
                farthest = max(farthest, nums[i] + i);
            }
            left = right + 1;
            right = farthest;
            ans++;
        }
        return ans;
    }
};