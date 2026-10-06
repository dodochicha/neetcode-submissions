class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();
        const int DIR[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> flow(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        auto dfs = [&](auto&& self, int i, int j) -> void {
            if (visited[i][j]) return;
            visited[i][j] = true;
            flow[i][j]++;
            for (int k = 0; k < 4; k++) {
                int ni = i + DIR[k][0];
                int nj = j + DIR[k][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && visited[ni][nj] == false && heights[ni][nj] >= heights[i][j]) {
                    self(self, ni, nj);
                }
            }
        };
        for (int j = 0; j < n; j++) {
            dfs(dfs, 0, j);
        }
        for (int i = 1; i < m; i++) {
            dfs(dfs, i, 0);
        }
        visited.assign(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++) {
            dfs(dfs, m - 1, j);
        }
        for (int i = 0; i < m - 1; i++) {
            dfs(dfs, i, n - 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (flow[i][j] == 2) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
