class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans;
        const int n = tokens.size();
        for (int i = 0; i < n; i++) {
            int digit = 0;
            bool neg = false;
            for (int j = 0; j < tokens[i].size(); j++) {
                if (!isdigit(tokens[i][j]) && tokens[i].size() == 1) {
                    int b = st.top(); st.pop();
                    int a = st.top(); st.pop();
                    int result = 0;
                    if (tokens[i][j] == '+') result = a + b;
                    else if (tokens[i][j] == '-') result = a - b;
                    else if (tokens[i][j] == '*') result = a * b;
                    else if (tokens[i][j] == '/') result = a / b;
                    st.push(result);
                    break;
                }
                else {
                    digit *= 10;
                    if (tokens[i][j] != '-') digit += (tokens[i][j] - '0');
                    else neg = true;
                    if (j == tokens[i].size() - 1) st.push((neg) ? -digit : digit);
                }
            }
        }
        return st.top();
    }
};
