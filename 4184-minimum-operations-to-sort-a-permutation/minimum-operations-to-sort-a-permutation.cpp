class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return 0;

        int count=0;
        int x;
        int x2;

        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                count++;
                x2=i;
            }
            else{
                x=i;
            }
        }

        if(count!=0&&count!=1&&count!=n-1) return -1;

        if(count==1&&nums[0]<nums[n-1]) return 0;

        if(count==n-1){
            return min(((x+1)%n),((n-x-1)%n))+1;
        }
        else{
            return min(((x2+1)%n),((n-x2-1)%n+2));
        }

    }
};