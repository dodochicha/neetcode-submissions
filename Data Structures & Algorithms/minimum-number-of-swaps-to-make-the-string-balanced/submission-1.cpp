class Solution {
public:
    int minSwaps(string s) {
        const int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == ']') {
                if (st.top() == '[') {
                    st.pop();
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        return (st.size() / 2 + 1) / 2;
    }
};



