class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<string> ans;
        auto dfs = [&](auto&& self, int i, int j, string word) -> bool {
            visited[i][j] = true;
            if (word[0] != board[i][j]) {
                visited[i][j] = false;
                return false;
            }
            if (word.size() == 1 && word[0] == board[i][j]) return true;
            for (int k = 0; k < 4; k++) {
                int ni = i + DIR[k][0];
                int nj = j + DIR[k][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    if (self(self, ni, nj, word.substr(1))) return true;
                }
            }
            visited[i][j] = false;
            return false;
        };
        for (int k = 0; k < words.size(); k++) {
            bool tmp = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (tmp) continue;
                    visited.assign(m, vector<bool>(n, false));
                    if (dfs(dfs, i, j, words[k])) {
                        ans.push_back(words[k]);
                        tmp = true;
                    }
                }
            }
        }
        return ans;
    }
};
