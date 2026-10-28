class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        vector<int> res(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0;  j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int sum = a * b + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        for (int i: res) {
            if (i == 0 && ans.empty()) continue;
            ans += to_string(i);
        }
        return ans.empty() ? "0" : ans;
    }
};
