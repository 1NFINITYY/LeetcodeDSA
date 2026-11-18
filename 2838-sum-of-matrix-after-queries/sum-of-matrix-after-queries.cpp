class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans=0;
        vector<bool> row(n,false);
        vector<bool> col(n,false);

        int usedrows=0;
        int usedcols=0;

        int x=queries.size();

        int type;
        int index;
        int val;

        for(int i=x-1;i>=0;i--){

            type=queries[i][0];
            index=queries[i][1];
            val=queries[i][2];

            if(type==0){
                if(row[index]==false){
                    ans+=(val*(n-usedcols));
                    usedrows++;
                    row[index]=true;
                }
            }
            else{
                if(col[index]==false){
                    ans+=(val*(n-usedrows));
                    usedcols++;
                    col[index]=true;
                }
            }
        }

        return ans;

    }
};
