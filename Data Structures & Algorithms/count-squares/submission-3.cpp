class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;

    CountSquares() {}

    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }

    int get(int x, int y) {
        auto it = cnt.find(x);
        if (it == cnt.end()) return 0;

        auto jt = it->second.find(y);
        return jt == it->second.end() ? 0 : jt->second;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;

        auto it = cnt.find(x);
        if (it == cnt.end()) return 0;

        for (auto [ny, freq] : it->second) {
            if (ny == y) continue;

            int d = abs(ny - y);

            ans += freq * get(x + d, y) * get(x + d, ny);
            ans += freq * get(x - d, y) * get(x - d, ny);
        }

        return ans;
    }
};