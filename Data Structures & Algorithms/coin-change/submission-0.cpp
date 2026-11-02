class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            int num = INT_MAX / 2;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    num = min(num, dp[i-coins[j]] + 1);
                }
            }
            dp[i] = num;
        }
        return (dp[amount] == INT_MAX / 2) ? -1 : dp[amount];
    }
};
