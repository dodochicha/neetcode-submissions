class Solution {
public:
    int findMin(vector<int> &nums) {
        int ref = nums[0];
        int right = nums.size();
        int left = 0;
        while (left < right) { // find first index < nums[0]
            int mid = left + (right - left) / 2;
            if (nums[mid] < ref) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return (right == nums.size()) ? nums[0] : nums[left];
    }
};
