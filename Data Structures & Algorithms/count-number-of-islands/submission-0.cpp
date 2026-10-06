class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        auto dfs = [&] (this auto&& dfs, int x, int y) {
            if (grid[y][x] == '0' || visited[y][x]) return;
            visited[y][x] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[ny][nx] == false && grid[ny][nx] == '1') {
                    dfs(nx, ny);
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == '1') ans++;
                dfs(j, i);
            }
        }
        return ans;
    }
};
