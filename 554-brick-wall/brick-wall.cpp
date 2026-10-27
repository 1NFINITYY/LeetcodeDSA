class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        int m=wall[0].size();

        long long sum=0;

        for(int i=0;i<m;i++){
            sum+=wall[0][i];
        }

        unordered_map<long long,int> mp;
        long long temp;

        for(int i=0;i<n;i++){
            temp=0;
            m=wall[i].size();
            for(int j=0;j<m;j++){
                temp+=wall[i][j];
                mp[temp]++;
            }
        }

        int ans=0;

        for(auto i:mp){
            if(i.first==sum){
                continue;
            }
            ans=max(ans,i.second);
        }

        return n-ans;
    }
};
