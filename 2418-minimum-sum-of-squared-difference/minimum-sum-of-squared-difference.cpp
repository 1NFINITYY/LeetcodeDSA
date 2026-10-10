class Solution {
public:

using LL = long long;

    static bool solve(const vector<int>& a,const vector<int>& b){
        return a[0]>b[0];
    }

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int k=k1+k2;
        vector<vector<int>> nums;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[abs(nums1[i]-nums2[i])]++;
        }

        for(auto it:mp){
            nums.push_back({it.first,it.second});
        }

        sort(nums.begin(),nums.end(), solve);

        int i=0;

        n=nums.size();

        while(i<n){
            if(i==n-1){
                if(nums[i][0]<=k/nums[i][1]){
                    return 0;
                }
                break;
            }

            if((nums[i][0]-nums[i+1][0])>k/nums[i][1]){
                break;
            }
            else{
                nums[i+1][1]+=nums[i][1];
                k-=(nums[i][0]-nums[i+1][0])*nums[i][1];
            }
            i++;
        }

        long long sum=0;

        for(int j=i+1;j<n;j++){
            sum += 1LL * nums[j][0] * nums[j][0] * nums[j][1];
        }

        int l=k/nums[i][1];
        k=k-(l*nums[i][1]);
        nums[i][0]=nums[i][0]-l;

        sum+=1ll*k*(nums[i][0]-1)*(nums[i][0]-1);
        sum+=1ll*(nums[i][1]-k)*nums[i][0]*nums[i][0];
        
        return sum;
    }
};

