class Solution {
public:

    int matching(string& a,string& b){
        int n=a.length();
        int m=b.length();

        int run = min(n,m);
        int ans=-1;

        for(int i=0;i<n&&n-i>=m;i++){
            if(a.substr(i,m)==b) return -2;
        }
        for(int i=0;i<m&&m-i>=n;i++){
            if(b.substr(i,n)==a) return -3;
        }

        for(int i=0;i<run;i++){
            if(a.substr(n-i-1)==b.substr(0,i+1)){
                ans=max(ans,i);
            }
        }

        return ans+1;
    } 

    string merge(string& a,string& b){

        int v=matching(a,b);

        if(v==-2) return a;
        if(v==-3) return b;

        string ans=a+b.substr(v);

        cout<<v<<endl<<ans<<endl;

        return ans;
    }

    string solve(string& a,string& b,string& c){

        string ab=merge(a,b);
        string ans=merge(ab,c);

        return ans;  
    }

    string lexo(string& a, string& b){
        int n=a.length();
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                return b;
            }
            else if(b[i]>a[i]){
                return a;
            }
        }

        return a;
    }

    string minimumString(string a, string b, string c){

        string abc=solve(a,b,c);
        string acb=solve(a,c,b);
        string bac=solve(b,a,c);
        string bca=solve(b,c,a);
        string cab=solve(c,a,b);
        string cba=solve(c,b,a);

        string ans;

        int si=INT_MAX;

        if(si>abc.length()){
            ans=abc;
            si=abc.length();
        }
        else if(si==abc.length()) ans=lexo(abc,ans);

        if(si>acb.length()){
            ans=acb;
            si=acb.length();
        }
        else if(si==acb.length()) ans=lexo(acb,ans);

        if(si>bac.length()){
            ans=bac;
            si=bac.length();
        }
        else if(si==bac.length()) ans=lexo(bac,ans);

        if(si>bca.length()){
            ans=bca;
            si=bca.length();
        }
        else if(si==bca.length()) ans=lexo(bca,ans);

        if(si>cab.length()){
            ans=cab;
            si=cab.length();
        }
        else if(si==cab.length()) ans=lexo(cab,ans);

        if(si>cba.length()){
            ans=cba;
            si=cba.length();
        }
        else if(si==cba.length()) ans=lexo(cba,ans);

        return ans;

    }
};
