class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        auto dfs = [&](auto&& self, int i, int j) -> int {
            const int DIR[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            grid[i][j] = 2;
            int area = 1;
            for (int k = 0; k < 4; k++) {
                int ni = i + DIR[k][1];
                int nj = j + DIR[k][0];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                    area += self(self, ni, nj);
                }
            }
            return area;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(dfs, i, j));
                }
            }
        }
        return ans;
    }
};