class Solution {
public:
    int minimumOperations(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();

        int ans=0;

        for(int i=0;i<m;i++){
            int maxi=-1;
            for(int j=0;j<n;j++){
                if(nums[j][i]>maxi){
                    maxi=nums[j][i];
                }
                else{
                    ans+=maxi+1-nums[j][i];
                    maxi++;
                }
            }
        }

        return ans;
    }
};