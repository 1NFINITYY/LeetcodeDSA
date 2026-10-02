class Solution {
public:

    void helper(int n,int count,string s,vector<string>& ans){

        if(count<0||n<0) return;
        if(n==0&&count==0){
            ans.push_back(s);
            return;
        }

        helper(n-1,count+1,s+'(',ans);

        helper(n,count-1,s+')',ans);

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        helper(n,0,temp,ans);;
        return ans;
    }
};