class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();

        int lessthan=-1;
        int count=0;

        for(int i=0;i<n;i++){
            if(nums[i]<target){
                lessthan++;
            }
            else if(nums[i]==target){
                count++;
            }
        }

        vector<int> ans;

        while(count){
            ans.push_back(lessthan+1);
            lessthan++;
            count--;
        }

        return ans;
    }
};