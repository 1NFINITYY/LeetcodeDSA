class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        
        if(n==3) return 0;

        int s1=INT_MAX;
        int s2=INT_MAX,s3=INT_MAX;

        int a1=INT_MIN;
        int a2=INT_MIN,a3=INT_MIN;

        for(int i:nums){
            if(s1>i){
                s3=s2;
                s2=s1;
                s1=i;
            }
            else if(s2>i){
                s3=s2;
                s2=i;
            }
            else if(s3>i){
                s3=i;
            }
            if(a1<i){
                a3=a2;
                a2=a1;
                a1=i;
            }
            else if(a2<i){
                a3=a2;
                a2=i;
            }
            else if(a3<i){
                a3=i;
            }
        }

        int ans=INT_MAX;

        ans=min(ans,abs(a2-s2)); 
        ans=min(ans,abs(a1-s3));
        ans=min(ans,abs(a3-s1));

        return ans;
    }
};

