class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long right = 10000000000;
        long long left = -10000000000;
        long long mid = 0;
        while (right > left) {
            mid = left + (right - left) / 2;
            long long k_cur = 0;
            for (int i = 0; i < nums1.size(); i++) {
                // nums[i] = -8
                // mid = 8
                // q = -1
                // -2, -1, 0, 1, 2
                int l = 0;
                int r = nums2.size();
                if (nums1[i] < 0) { // first product <= k
                    int m;
                    while (l < r) {
                        m = l + (r - l) / 2;
                        long long product = nums1[i] * nums2[m];
                        if (product <= mid) r = m;
                        else l = m + 1;
                    }
                    k_cur += (nums2.size() - l);
                }
                else {
                    int m;
                    while (l < r) { // first product > k
                        m = l + (r - l) / 2;
                        long long product = nums1[i] * nums2[m];
                        if (product > mid) r = m;
                        else l = m + 1;
                    }
                    k_cur += l;
                }
            }
            if (k_cur >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};