class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int start = 0;
        int end = 0;
        for (int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
        }
        int len = 1;
        int total = gas[0];
        while (len != n) {
            if (total < 0) {
                start = (start == 0) ? n - 1 : start - 1;
                total += gas[start];
            }
            else {
                end++;
                total += gas[end];
            }
            len++;
        }
        if (total >= 0) return start;
        else return -1;
    }
};

