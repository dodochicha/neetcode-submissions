class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minimum = nums[0];
        int maximum = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp = maximum;
            maximum = max(nums[i], max(maximum * nums[i], minimum * nums[i]));
            minimum = min(nums[i], min(tmp * nums[i], minimum * nums[i]));
            ans = max(ans, maximum);
        }
        return ans;
    }
};
