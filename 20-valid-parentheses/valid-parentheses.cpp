class Solution {
public:
    bool isValid(string s) {

        int n=s.size();

        stack<char> st;

        for(auto i:s){
            if(i=='('||i=='['||i=='{'){
                st.push(i);
            }
            else{
                if(st.empty()) return false;
                char top=st.top();
                st.pop();

                if(top=='('&&(i==']'||i=='}')) return false;
                if(top=='['&&(i==')'||i=='}')) return false;
                if(top=='{'&&(i==']'||i==')')) return false;

            }
        }
        
        if(!st.empty()) return false;

        return true;
        
    }
};