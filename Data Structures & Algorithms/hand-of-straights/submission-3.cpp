class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n = hand.size();
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[hand[i]]++;
        }
        if (n % groupSize != 0) return false;
        for (auto x: hand) {
            if (freq[x] == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                if (freq[x+i] == 0) return false;
                else {
                    freq[x+i]--;
                }
            }
        }
        return true;
    }
};
