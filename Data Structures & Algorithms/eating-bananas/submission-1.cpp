class Solution {
public:
    int numHour(vector<int>& piles, int k) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] + k - 1) / k;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();
        int maxP = 0;
        int left = 1;
        for (int i = 0; i < n; i++) {
            maxP = max(maxP, piles[i]);
        }
        int right = ((maxP + h - 1) / h) * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numHour(piles, mid) <= h) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
