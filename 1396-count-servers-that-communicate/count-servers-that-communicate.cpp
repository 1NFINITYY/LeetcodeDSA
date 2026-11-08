class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();

        int ans=0;

        vector<int> row(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]++;
                }
            }
            if(row[i]>1){
                ans+=row[i];
            }
        }
        cout<<ans;
        int noofservers;
        int noofactiveservers;

        for(int i=0;i<m;i++){
            noofservers=0;
            noofactiveservers=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1) noofservers++;
                if(grid[j][i]==1&&row[j]<=1) noofactiveservers++;
            }
            if(noofservers>1){
                ans+=noofactiveservers;
            }
        }

        return ans;

    }
};