class Solution {
public:
    bool checkValidString(string s) {
        const int n = s.size();
        int low = 0; // least unmatched (
        int high = 0; // most unmatched (
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                low++;
                high++;
            }
            else if (s[i] == '*') {
                low = max(0, low - 1);
                high++;
            }
            else {
                if (high == 0) return false;
                low = max(0, low - 1);
                high--;
            }
        }
        return high >= 0 && low == 0;
    }
};
