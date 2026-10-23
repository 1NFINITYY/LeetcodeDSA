class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> temp=nums;
        int n=nums.size();

        sort(temp.begin(),temp.end());

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            if(temp[i]!=nums[i]){
                ans=ans&nums[i];
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
