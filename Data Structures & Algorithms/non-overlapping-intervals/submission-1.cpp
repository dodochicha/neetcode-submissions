class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1] || a[1] == b[1] && a[0] < a[0];
        });
        int i = 1;
        int ans = 0;
        int left = intervals[0][0];
        int right = intervals[0][1];
        while (i < n) {
            if (intervals[i][0] < right) {
                ans++;
            }
            else {
                left = intervals[i][0];
                right = intervals[i][1];
            }
            i++;
        }
        return ans;
    }
};
