class Solution {
public:

    char solve(char s,int x){
        int n=s-'a';
        n+=x;
        n=n%26;
        return 'a'+n;
    }

    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=(shifts[i]%26);
            sum=sum%26;
            shifts[i]=sum;
        }

        string ans="";
        for(int i=0;i<n;i++){
            ans+=solve(s[i],shifts[i]);
        }

        return ans;
    }
};