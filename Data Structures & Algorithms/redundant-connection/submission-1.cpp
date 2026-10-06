class DSU {
    vector<int> pa;
    vector<int> size;
    public:
        DSU(int n): pa(n), size(n) {
            for (int i = 0; i < n; i++) {
                pa[i] = i;
                size[i] = 1;
            }
        } 
        int find(int v) {
            if (pa[v] != v) {
                pa[v] = find(pa[v]);
            }
            return pa[v];
        }

        bool unite(int v, int u) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false;
            if (size[pu] < size[pv]) {
                swap(pu, pv);
            }
            size[pu] += size[pv];
            pa[pv] = pu;
            return true;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        DSU* dsu = new DSU(n+1);
        for (int i = 0; i < edges.size(); i++) {
            if (!dsu->unite(edges[i][0], edges[i][1])) return edges[i];
        }
        return vector<int>();
    }
};
