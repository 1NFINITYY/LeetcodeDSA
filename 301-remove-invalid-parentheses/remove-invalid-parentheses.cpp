class Solution {
public:

    void helper(string& s,set<string>& ans,int& n,int i,int count,string& temp,int& x){
        if(count<0){
            return;
        }
        if(i==n&&count==0&&temp.size()==n-x){
            ans.insert(temp);
            return;
        }
        if(i==n){
            return;
        }

        if(s[i]=='('){
            helper(s,ans,n,i+1,count,temp,x);
            temp+=s[i];
            helper(s,ans,n,i+1,count+1,temp,x);
            temp.pop_back();
            return;
        }

        if(s[i]==')'){
            helper(s,ans,n,i+1,count,temp,x);
            temp+=s[i];
            helper(s,ans,n,i+1,count-1,temp,x);
            temp.pop_back();
            return;
        }

        temp+=s[i];
        helper(s,ans,n,i+1,count,temp,x);
        temp.pop_back();
        return;
        
    }

    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        set<string> ansi;
        int x=0;
        int count=0;
        for(auto i:s){
            if(i=='('){
                count++;
            }
            else if(i==')'&&count==0){
                x++;
            }
            else if(i==')'){
                count--;
            }
        }
        x+=count;
        string temp="";
        helper(s,ansi,n,0,0,temp,x);

        vector<string> ans;

        for(auto i:ansi){
            ans.push_back(i);
        }
        return ans;
    }
};