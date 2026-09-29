class Solution {
public:

    bool helper(int start,int end,int& startx,int& endx,vector<vector<char>> &grid,int count,vector<vector<vector<int>>>& dp){

        if(grid[start][end]=='('){
            count++;
        }
        else{
            count--;
        }

        if(count<0){
            return false;
        }

        if(start==startx&&end==endx&&count==0){
            return true;
        }

        if(dp[start][end][count]!=-1){
            return dp[start][end][count];
        }

        bool ans=false;

        if(start+1<=startx&&helper(start+1,end,startx,endx,grid,count,dp)){
            ans=true;
        }

        if(end+1<=endx&&helper(start,end+1,startx,endx,grid,count,dp)){
            ans=true;
        }

        return dp[start][end][count]=ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==')'||grid[n-1][m-1]=='('||m+n-1%2==1){
            return false;
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (201,-1)));

        n--;
        m--;

        bool ans=helper(0,0,n,m,grid,0,dp);

        return ans;

    }
};