class Solution {
public:
    string processStr(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                ans+=s[i];
            }
            if(s[i]=='*'&&ans.length()>0){
                ans.pop_back();
            }
            if(s[i]=='#'){
                ans+=ans;
            }
            if(s[i]=='%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};