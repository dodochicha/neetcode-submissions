class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> cnt;
        for (int i = 0; i < tasks.size(); i++) {
            cnt[tasks[i]]++;
        }
        int maxFreq = 0;
        int maxCnt = 0;
        for (auto pair: cnt) {
            maxFreq = max(maxFreq, pair.second);
        }
        for (auto pair: cnt) {
            if (pair.second == maxFreq) maxCnt++;
        }
        return max((int)tasks.size(), maxCnt + (n + 1) * (maxFreq - 1));
    }
};
