class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> e(n);
        int vis = 0;
        bool ans = true;
        for (int i = 0; i < edges.size(); i++) {
            e[edges[i][0]].push_back(edges[i][1]);
            e[edges[i][1]].push_back(edges[i][0]);
        }
        auto dfs = [&](auto&& self, int v, int fa) -> bool {
            if (visited[v]) return false;
            bool ans = true;
            vis++;
            visited[v] = true;
            for (int i = 0; i < e[v].size(); i++) {
                if (e[v][i] != fa) ans = ans && self(self, e[v][i], v);
            }
            return ans;
        };
        ans = dfs(dfs, 0, -1) && (vis == n);
        return ans;
    }
};
