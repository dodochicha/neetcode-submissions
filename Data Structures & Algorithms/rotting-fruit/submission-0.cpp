class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        queue<tuple<int, int, int>> q;
        const int DIR[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int fresh = 0;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while (!q.empty()) {
            auto [i, j, depth] = q.front();
            for (int k = 0; k < 4; k++) {
                int ni = i + DIR[k][0];
                int nj = j + DIR[k][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                    q.push({ni, nj, depth + 1});
                    grid[ni][nj] = 2;
                    fresh--;
                    ans = max(ans, depth + 1);
                }
            }
            q.pop();
        }
        return (fresh == 0) ? ans : -1;
    }
};
