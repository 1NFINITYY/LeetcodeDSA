class Solution {
public:
    int mod=1e9+7;
    int n;
    int solve(vector<int>& arr,vector<int>& dp,int i){
        if(i<0) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        if(arr[i]%2==0){
            int ans=solve(arr,dp,i-1)%mod;
            dp[i]=ans;
            return ans;
        }
        int countofodds=0;
        int ans=1;

        for(int x=i-1;x>=0;x--){
            if(countofodds==0&&arr[x]%2==0){
                ans++;
            }
            if(arr[x]%2==1){
                countofodds++;
            }
            if(arr[x]%2==1&&countofodds%2==0&&countofodds>0){
                ans=(ans+solve(arr,dp,x))%mod;
                break;
            }
        }

        dp[i]=ans;
        return ans;
    }

    int numOfSubarrays(vector<int>& arr) {
        n=arr.size();
        int ans=0;

        vector<int> dp(n,-1);
        int temp;

        for(int i=n-1;i>=0;i--){
            if(dp[i]==-1){
                temp=solve(arr,dp,i);
            }
            cout<<dp[i]<<" ";
            ans=(ans+dp[i])%mod;
        }

        return ans;
    }
};



