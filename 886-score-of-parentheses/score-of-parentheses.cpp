class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int ans = 0;
        int depth = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push('(');
                depth++;
            }
            else {
                st.pop();
                depth--;

                if(s[i-1] == '(') {
                    ans += (1 << depth);
                }
            }
        }

        return ans;
    }
};