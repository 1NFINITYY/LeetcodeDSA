class Solution {
public:
    string reverseParentheses(string s) {

        stack<int> st;
        string ans;

        for (char c : s){

            if (c=='('){
                st.push(ans.length());
            } 
            else if (c==')'){
                int top=st.top();
                st.pop();
                reverse(ans.begin()+top,ans.end());
            } 
            else {
                ans+=c;
            }
        }
        return ans;
    }
};