class Solution {
public:

    int n;
    int m;
    int o;

    int solve(string& s1, string& s2, string& s3,int i,int j,vector<vector<int>>& dp){
        if(i>n||j>m||i+j>o){
            return 0;
        }
        if(i==n&&j==m&&i+j==o) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]!=s3[i+j]&&s2[j]!=s3[i+j]){
            dp[i][j]=0;
            return 0;
        }
        if(s1[i]==s3[i+j]&&s2[j]==s3[i+j]){
            dp[i][j]=0;
            dp[i][j]=solve(s1,s2,s3,i+1,j,dp)|solve(s1,s2,s3,i,j+1,dp);
            return dp[i][j];
        }
        if(s1[i]==s3[i+j]){
            dp[i][j]=0;
            dp[i][j]=solve(s1,s2,s3,i+1,j,dp);
            return dp[i][j];
        }
        if(s2[j]==s3[i+j]){
            dp[i][j]=0;
            dp[i][j]=solve(s1,s2,s3,i,j+1,dp);
            return dp[i][j];
        }

        return 0;
    }



    bool isInterleave(string s1, string s2, string s3) {
        n=s1.length();
        m=s2.length();
        o=s3.length();

        if(n==0&&m==0&&o==0)return true;
        if(n==0&&m==0&&o>0)return false;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        int ans=solve(s1,s2,s3,0,0,dp);

        if(ans==0) return false;

        return ans;

    }
};