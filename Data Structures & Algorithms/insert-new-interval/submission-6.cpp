class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> ans;
        const int n = intervals.size();
        int idx = 0;
        bool put = false;
        while (idx < n) {
            if (intervals[idx][1] < newInterval[0]) { // interval, new
                ans.push_back(intervals[idx]);
            }
            else if (intervals[idx][0] > newInterval[1]) { // new, interval
                if (!put) ans.push_back({left, right});
                ans.push_back(intervals[idx]);
                put = true;
            }
            else {
                left = min(left, intervals[idx][0]);
                right = max(right, intervals[idx][1]);
            }
            idx++;
        }
        if (!put) ans.push_back({left, right});
        return ans;
    }
};
