class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int ref = nums[0];
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < ref) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        int r = left;
        rotate(nums.begin(), nums.begin() + r, nums.end());
        left = 0;
        right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (left == n || nums[left] != target) return -1;
        else return (left + r) % n;
    }
};
