class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> dp(m, vector(n, -1));
        int ans = 1;
        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
            const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            if (dp[i][j] != -1) return;
            for (int k = 0; k < 4; k++) {
                int ny = i + DIR[k][0];
                int nx = j + DIR[k][1];
                if (ny >= 0 && ny < m && nx >= 0 && nx < n) {
                    if (matrix[i][j] > matrix[ny][nx]) {
                        dfs(ny, nx);
                        dp[i][j] = max(dp[i][j], dp[ny][nx] + 1);
                    }
                    else {
                        dp[i][j] = max(0, dp[i][j]);
                    }
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j);
                ans = max(ans, dp[i][j] + 1);
            }
        }
        return ans;
    }
};
