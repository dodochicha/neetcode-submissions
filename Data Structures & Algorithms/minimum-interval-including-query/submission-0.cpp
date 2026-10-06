class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int n = queries.size();
        vector<pair<int, int>> qri;
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int itr_idx = 0;
        for (int i = 0; i < n; i++) {
            qri.push_back({queries[i], i});
        }
        sort(qri.begin(), qri.end());
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++) {
            auto [q, idx] = qri[i];
            while (itr_idx < intervals.size() && q >= intervals[itr_idx][0]) {
                int start = intervals[itr_idx][0];
                int end = intervals[itr_idx][1];
                int len = end - start + 1;
                pq.push({len, end});
                itr_idx++;
            }
            if (pq.empty()) continue;
            else {
                while (!pq.empty() && pq.top().second < q) {
                    pq.pop();
                }
                if (!pq.empty()) {
                    ans[idx] = pq.top().first;
                }
            }
        }
        return ans;
    }
};
