class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        int ans = 0;
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        auto dfs = [&](auto&& self, int v) -> void {
            visited[v] = true;
            for (int i = 0; i < adj[v].size(); i++) {
                if (!visited[adj[v][i]]) self(self, adj[v][i]);
            }
        };
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(dfs, i);
            }
        }
        return ans;
    }
};
