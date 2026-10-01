class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(101,0);
        for(auto i:nums){
            count[i]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(count[nums[i]]!=3) continue;
            int j=i+1;
            while(j<n&&nums[j]!=nums[i]){
                j++;
            }
            if(j>=n) continue;
            int space=j-i;
            if(j+space<n&&nums[j+space]==nums[i]){
                ans++;
            }
        }
        return ans;
    }
};