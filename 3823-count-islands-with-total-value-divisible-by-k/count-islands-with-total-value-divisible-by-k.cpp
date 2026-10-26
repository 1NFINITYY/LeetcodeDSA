class Solution {
public:

    int islandvalue(vector<vector<int>>& grid,int i,int j,int& n,int& m,int& k){
        if(i<0||i>=n||j<0||j>=m) return 0;
        if(grid[i][j]==0) return 0;

        int ans=grid[i][j];
        grid[i][j]=0;

        ans+=islandvalue(grid,i+1,j,n,m,k);
        ans=ans%k;
        ans+=islandvalue(grid,i,j+1,n,m,k);
        ans=ans%k;
        ans+=islandvalue(grid,i-1,j,n,m,k);
        ans=ans%k;
        ans+=islandvalue(grid,i,j-1,n,m,k);
        ans=ans%k;

        return ans;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int value;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    value=islandvalue(grid,i,j,n,m,k);
                    if(value%k==0){
                        ans++;
                    }
                }
            }
        }

        return ans;

    }
};