class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> st;

        int temp;
        int temp1;

        for(string i:tokens){
            if(i=="+"){
                temp=st.top();
                st.pop();
                temp1=st.top();
                st.pop();

                temp+=temp1;
                st.push(temp);
            }
            else if(i=="-"){
                temp=st.top();
                st.pop();
                temp1=st.top();
                st.pop();

                temp=temp1-temp;
                st.push(temp);
            }
            else if(i=="*"){
                temp=st.top();
                st.pop();
                temp1=st.top();
                st.pop();

                temp=temp*temp1;
                st.push(temp);
            }
            else if(i=="/"){
                temp=st.top();
                st.pop();
                temp1=st.top();
                st.pop();

                temp=temp1/temp;
                st.push(temp);
            }
            else{
                temp=stoi(i);
                st.push(temp);
            }
        }

        int ans=st.top();
        return ans;
    }
};