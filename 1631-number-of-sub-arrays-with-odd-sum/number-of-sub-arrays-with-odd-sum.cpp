class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int noofeven=0;
        int mod=1e9+7;

        int  prev=0;
        int pprev=0;
        int temp=0;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                noofeven++;
                ans=(ans+prev)%mod;
            }
            else{
                temp=ans;
                ans=(ans+pprev+1+noofeven)%mod;
                noofeven=0;
                pprev=prev;
                prev = (ans - temp + mod) % mod;
            }
        }


        return ans;
    }
};



