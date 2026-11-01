class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        vector<int> merged;
        int n=nums.size();
        int j,num;
        int fin;
        for(int i=0;i<n;i+=2){
            j=1;
            num=nums[i+1];
            while(num>0){
                num=num/10;
                j=j*10;
            }
            fin=(nums[i]*j)+nums[i+1];
            merged.push_back(fin);
        }
        int ans=INT_MAX;
        for(auto i:merged){
            ans=min(ans,i);
        }
        return ans;
    }
};