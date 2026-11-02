class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minimum = nums[0];
        int maximum = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = maximum * nums[i];
            int b = minimum * nums[i];
            maximum = max(nums[i], max(a, b));
            minimum = min(nums[i], min(a, b));
            ans = max(ans, maximum);
        }
        return ans;
    }
};
