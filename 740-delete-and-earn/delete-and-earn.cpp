class Solution {
public:

    int solve(vector<vector<int>>& array,int i,vector<int>& dp){
        if(i<0){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int ans=0;
        int ans1;

        //liya
        if(i-1>=0&&array[i-1][0]+1!=array[i][0]){
            ans1=solve(array,i-1,dp)+array[i][1];
        }
        else{
            ans1=solve(array,i-2,dp)+array[i][1];
        }
        

        //nhi liya 
        int ans2=solve(array,i-1,dp);

        ans=max(ans1,ans2);

        dp[i]=ans;
        return ans;
    }

    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }

        sort(nums.begin(),nums.end());
        vector<vector<int>> array;
        int count=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                array.push_back({nums[i],nums[i]*count});
                count=1;
            }
            else{
                count++;
            }
        }
        
        array.push_back({nums[n-1],count*nums[n-1]});

        n=array.size();

        vector<int> dp(n+1,-1);

        dp[0]=array[0][1];

        int ans=solve(array,n-1,dp);

        return ans;

    }
};
