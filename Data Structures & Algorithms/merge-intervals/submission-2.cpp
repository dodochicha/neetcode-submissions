class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0];
        int right = intervals[0][1];
        int i = 1;
        vector<vector<int>> ans;
        while (i < n) {
            if (intervals[i][0] <= right) {
                right = max(right, intervals[i][1]);
            }
            else {
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            i++;
        }
        ans.push_back({left, right});
        return ans;
    }
};
