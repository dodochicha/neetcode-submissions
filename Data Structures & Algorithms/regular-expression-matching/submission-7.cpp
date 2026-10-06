#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] 表示 s 的前 i 個字元與 p 的前 j 個字元是否匹配
        // 初始化大小為 (m+1) x (n+1)，預設為 false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: 空字串匹配空 pattern 為真
        dp[0][0] = true;
        
        // 處理 pattern 為空字串 s，但 p 有 '*' 的情況 (例如 s="" p="a*b*")
        // '*' 可以讓前面的字元消失，所以 dp[0][j] 可以參考 dp[0][j-2]
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // 開始填表
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 如果 pattern 當前是 '*'
                if (p[j - 1] == '*') {
                    // 情況 1: '*' 匹配 0 次前一個字元 (直接忽略 x* 這一組)
                    // 所以看 j-2 的狀態
                    bool matchZero = dp[i][j - 2];
                    
                    // 情況 2: '*' 匹配 1 次或多次
                    // 前提是: s 的當前字元 (s[i-1]) 必須和 p 的前一個字元 (p[j-2]) 相同，或是 p[j-2] 是 '.'
                    bool matchOneOrMore = false;
                    char preChar = p[j - 2];
                    if (preChar == '.' || preChar == s[i - 1]) {
                        matchOneOrMore = dp[i - 1][j]; // s 往前縮，但 p 保持在 '*' 狀態
                    }
                    
                    dp[i][j] = matchZero || matchOneOrMore;
                } 
                // 如果 pattern 當前是普通字元或是 '.'
                else {
                    if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};