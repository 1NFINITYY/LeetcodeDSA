class Solution {
public:

    void converttheisland(vector<vector<int>>& grid,int i, int j,int& n,int& m,vector<int>& x,vector<int>& y){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=1;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int currposx=top.first;
            int currposy=top.second;

            for(int i=0;i<4;i++){

                int xi=currposx+x[i];
                int yi=currposy+y[i];
                
                if(xi>=n||xi<0||yi>=m||yi<0){
                    continue;
                }

                if(grid[xi][yi]==0){
                    grid[xi][yi]=1;
                    q.push({xi,yi});
                }
                
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                grid[i][0]=1;
                q.push({i,0});
            }
            if(grid[i][m-1]==0){
                grid[i][m-1]=1;
                q.push({i,m-1});
            }
        }

        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                grid[0][i]=1;
                q.push({0,i});
            }
            if(grid[n-1][i]==0){
                grid[n-1][i]=1;
                q.push({n-1,i});
            }
        }

        vector<int> x={1,0,-1,0};
        vector<int> y={0,1,0,-1};

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int currposx=top.first;
            int currposy=top.second;

            for(int i=0;i<4;i++){

                int xi=currposx+x[i];
                int yi=currposy+y[i];
                
                if(xi>=n||xi<0||yi>=m||yi<0){
                    continue;
                }

                if(grid[xi][yi]==0){
                    grid[xi][yi]=1;
                    q.push({xi,yi});
                }
                
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    converttheisland(grid,i,j,n,m,x,y);
                }
            }
        }

        return ans;

    }
};