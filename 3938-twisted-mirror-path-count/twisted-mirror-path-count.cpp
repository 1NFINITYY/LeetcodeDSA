class Solution {
public:

    int n;
    int m;

    int MOD=1000000007;

    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp,bool updown){
        if(i<0||i>=n||j<0||j>=m) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(grid[i][j]==1){
            if(updown){
                return solve(grid,i-1,j,dp,0);
            }
            else{
                return solve(grid,i,j-1,dp,1);
            }
        }
        int up=solve(grid,i-1,j,dp,0);
        int left=solve(grid,i,j-1,dp,1);
        dp[i][j]=(up+left)%MOD;
        return dp[i][j];
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0]=1;
        int ans=solve(grid,n-1,m-1,dp,0);
        return ans;
    }
};