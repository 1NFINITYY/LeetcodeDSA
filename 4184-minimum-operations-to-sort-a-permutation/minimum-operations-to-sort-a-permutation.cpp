class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return 0;

        int count=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]) count++;
        }

        if(count!=0&&count!=1&&count!=n-1) return -1;

        if(count==1&&nums[0]<nums[n-1]) return 0;

        if(count==n-1){
            int x;
            for(int i=0;i<n;i++){
                if(nums[i]<nums[(i+1)%n]){
                    x=i;
                }
            }
            return min(((x+1)%n),((n-x-1)%n))+1;
        }
        else{
            int x2;
            for(int i=0;i<n;i++){
                if(nums[i]>nums[(i+1)%n]){
                    x2=i;
                }
            }
            return min(((x2+1)%n),((n-x2-1)%n+2));
        }

    }
};