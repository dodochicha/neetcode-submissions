/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        const int n = intervals.size();
        if (n == 0) return 0;
        vector<int> start;
        vector<int> end;
        int s = 1;
        int e = 0;
        int cnt = 1;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        while (s < n) {
            if (end[e] <= start[s]) {
                cnt--;
                e++;
            }
            else {
                cnt++;
                s++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// 1, 5, 10, 15
// 5, 10, 15, 20
