class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q;
        int taken = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int c = q.front();
            taken++;
            for (int i = 0; i < edges[c].size(); i++) {
                if (--indegree[edges[c][i]] == 0) {
                    q.push(edges[c][i]);
                }
            }
            q.pop();
        }
        return (taken == numCourses);
    }
};
