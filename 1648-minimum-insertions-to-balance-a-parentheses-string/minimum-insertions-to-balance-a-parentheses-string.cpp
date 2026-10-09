class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int ans=0;
        int count=0;

        string st="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st+=s[i];
            }
            else{
                if(i+1<n&&s[i+1]==')'){
                    st+='}';
                    i++;
                }
                else{
                    st+=')';
                }
            }
        }

        for(auto i:st){
            if(i=='('){
                count++;
            }
            else if(i=='}'){
                if(count==0){
                    ans++;
                }
                else{
                    count--;
                }
            }
            else{
                if(count==0){
                    ans+=2;
                }
                else{
                    ans++;
                    count--;
                }
            }
        }

        ans=ans+count*2;

        return ans;
    }
};