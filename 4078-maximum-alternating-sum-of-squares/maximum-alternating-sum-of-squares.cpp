class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=nums[i]*-1;
            }
        }
        sort(nums.begin(),nums.end());

        long long ans=0;

        for(int i=0;i<n/2;i++){
            ans-=nums[i]*nums[i];
            ans+=nums[n-i-1]*nums[n-i-1];
        }
        if(n%2==1){
            ans+=nums[(n/2)]*nums[(n/2)];
        }
        return ans;
    }
};