class Solution {
public:
    bool connect(string w1, string w2) {
        int diff = 0;
        for (int i = 0; i < w1.size(); i++) {
            diff += (w1[i] != w2[i]);
        }
        return (diff == 1);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        const int n = wordList.size();
        vector<vector<int>> edges(n);
        unordered_map<string, int> wordmap;
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        for (int i = 0; i < wordList.size(); i++) {
            wordmap[wordList[i]] = i;
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (connect(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        q.push({wordmap[beginWord], 1});
        visited[wordmap[beginWord]] = true;
        while (!q.empty()) {
            auto [s, depth] = q.front();
            q.pop();
            for (int i = 0; i < edges[s].size(); i++) {
                if (visited[edges[s][i]] == false) {
                    if (edges[s][i] == wordmap[endWord]) return depth + 1;
                    visited[edges[s][i]] = true;
                    q.push({edges[s][i], depth + 1});
                }
            }
        }
        return 0;
    }
};
