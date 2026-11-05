class CountSquares {
public:
    unordered_map<long long, int> cnt; 
    CountSquares() {

    }
    
    long long key(vector<int> point) {
        return (long long)point[1] << 32 | point[0];
    }

    int get(vector<int> point) {
        auto it = cnt.find(key(point));
        return it == cnt.end() ? 0 : it->second;
    }

    void add(vector<int> point) {
        cnt[key(point)]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        for (auto p: cnt) {
            int y = (int)(p.first >> 32);
            int x = p.first;
            if (y == point[1] && x == point[0]) continue;
            if (abs(y - point[1]) == abs(x - point[0])) {
                ans += p.second * get({point[0], y}) * get({x, point[1]});
            }
        }
        return ans;
    }
};
