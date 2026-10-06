class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 0);
        f[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int top = (i-1>=0) ? f[j] : 0;
                int left = (j-1>=0) ? f[j-1] : 0;
                f[j] = top + left;
            }
        }
        return f[n-1];
    }
};
