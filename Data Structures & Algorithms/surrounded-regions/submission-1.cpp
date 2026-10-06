class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int DIR[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        const int m = board.size();
        const int n = board[0].size();
        auto dfs = [&] (auto&& self, int i, int j) -> void {
            board[i][j] = '#';
            for (int k = 0; k < 4; k++) {
                int ni = i + DIR[k][0];
                int nj = j + DIR[k][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O') {
                    self(self, ni, nj);
                }
            }
        };
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(dfs, i, 0);
            if (board[i][n-1] == 'O') dfs(dfs, i, n-1);
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O') dfs(dfs, 0, j);
            if (board[m-1][j] == 'O') dfs(dfs, m-1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
