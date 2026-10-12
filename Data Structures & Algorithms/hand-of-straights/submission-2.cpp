class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n = hand.size();
        sort(hand.begin(), hand.end());
        unordered_map<int, int> dict;
        for (int i = 0; i < n; i++) {
            dict[hand[i]]++;
        }
        int start = 0;
        int cnt = 0;
        while (cnt != n) {
            int numStart = hand[start];
            dict[numStart]--;
            cnt++;
            while (dict[hand[start]] == 0) { // go next until find the minimum number
                start++;
                if (start == n) return (cnt == n && cnt % groupSize == 0);
            }
            for (int i = 1; i < groupSize; i++) {
                if (dict[numStart+i] != 0) {
                    dict[numStart+i]--;
                    cnt++;
                    while (dict[hand[start]] == 0) { // go next until find the minimum number
                        start++;
                        if (start == n) return (cnt == n && cnt % groupSize == 0);
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
