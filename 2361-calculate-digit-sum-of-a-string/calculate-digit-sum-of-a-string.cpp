class Solution {
public:
    string solve(string s,int& k){
        int n=s.length();
        int sum=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(i%k==0&&i>0){
                ans=ans+to_string(sum);
                sum=0;
            }
            sum+=s[i]-'0';
            if(i==n-1){
                ans=ans+to_string(sum);
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    string digitSum(string s, int k) {
        string temp=s;
        while(temp.length()>k){
            temp=solve(temp,k);
        }
        return temp;
    }
};