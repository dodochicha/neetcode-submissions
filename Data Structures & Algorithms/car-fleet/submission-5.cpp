class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<pair<int, int>> ps;
        int ans = 0;
        double lasttime = -1;
        for (int i = 0; i < n; i++) {
            ps.push_back(make_pair(position[i], speed[i]));
        }
        sort(ps.rbegin(), ps.rend());
        for (auto& [pos, spd]: ps) {
            double time = (double)(target - pos) / spd;
            if (time > lasttime) {
                ans++;
                lasttime = time;
            }
        }
        return ans;
    }
};
