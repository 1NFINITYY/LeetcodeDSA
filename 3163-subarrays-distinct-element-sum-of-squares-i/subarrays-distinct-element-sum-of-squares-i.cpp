class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> check(101,0);
            int count=0;
            for(int j=i;j<n;j++){
                if(check[nums[j]]==0){
                    check[nums[j]]++;
                    count++;
                }
                ans+=(count*count);
            }
        }

        return ans;
    }
};