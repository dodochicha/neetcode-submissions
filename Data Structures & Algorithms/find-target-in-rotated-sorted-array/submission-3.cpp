class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                if (nums[mid] < target || target < nums[left]) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
            else {
                if (nums[mid] >= target || target > nums[right]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return (nums[left] != target) ? -1 : left;
    }
};
