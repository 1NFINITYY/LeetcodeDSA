class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;

        if(k>=2*n){
            return n;
        }

        sort(nums.begin(),nums.end());

        int currvalue=nums[0]-k;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
                while(nums[i]-k>currvalue) currvalue++;

                while(mp.find(currvalue)!=mp.end()){
                    currvalue++;
                }

                if(currvalue>nums[i]+k){
                    continue;
                }

                mp[currvalue];
                currvalue++;
                ans++;
        }
        return ans;
    }
};

