class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;
        double ans = 0;
        int l = 0;
        int r = m;
        int Aleft;
        int Aright;
        int Bleft;
        int Bright;
        while (l <= r) {
            int mid = (l + r) / 2;
            Aleft = (mid <= 0) ? INT_MIN : nums1[mid-1];
            Aright = (mid >= m) ? INT_MAX : nums1[mid];
            Bleft = ((total + 1) / 2 - mid <= 0) ? INT_MIN : nums2[(total + 1) / 2 - mid - 1];
            Bright = ((total + 1) / 2 - mid >= n) ? INT_MAX : nums2[(total + 1) / 2 - mid];
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    return max(Aleft, Bleft);
                }
                else {
                    return (min(Aright, Bright) + max(Aleft, Bleft)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

// nums1[0...i]
// nums2[0...j]
// i + j = (total + 1) / 2
// cut[i] between nums[i-1] and nums[i]

// choose i
// j = (total + 1) / 2 - i
// Aleft = nums[i-1]
// Aright = nums[i]
// Bleft = nums[j-1]
// Bright = nums[j]
// condition: Aleft <= Bright and Bleft <= Aright