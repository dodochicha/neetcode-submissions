class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();

        // 外層迴圈：枚舉我們要將字串變成哪一個字母 ('A' 到 'Z')
        for (int i = 0; i < 26; i++) {
            char target = 'A' + i; // 當前的目標字母
            int start = 0;
            int diff = 0; // 視窗內「非目標字母」的數量
            
            // 內層迴圈：移動右指標
            for (int end = 0; end < n; end++) {
                // 如果當前字元不是目標字母，差異數 +1
                if (s[end] != target) {
                    diff++;
                }

                // 當差異數超過 k，移動左指標縮小視窗
                while (diff > k) {
                    // 如果即將移出的左邊界字元是「非目標字母」，差異數 -1
                    if (s[start] != target) {
                        diff--;
                    }
                    start++;
                }

                // 更新最大長度
                ans = max(ans, end - start + 1);
            }
        }
        return ans;
    }
};