class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans;
        queue<int> q;
        int taken = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int c = q.front();
            ans.push_back(c);
            taken++;
            for (int i = 0; i < edges[c].size(); i++) {
                if (--indegree[edges[c][i]] == 0) q.push(edges[c][i]);
            }
            q.pop();
        }
        return (taken == numCourses) ? ans : vector<int>();
    }
};
