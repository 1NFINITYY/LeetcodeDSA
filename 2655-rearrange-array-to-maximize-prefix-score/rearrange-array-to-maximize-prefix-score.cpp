class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();

        vector<int> neg;
        long long sum=0;
        int ans=0;

        for(int i:nums){
            if(i>0){
                ans++;
                sum+=i;
            }
            else{
                neg.push_back(i);
            }
        }

        sort(neg.begin(),neg.end());

        n=neg.size();

        for(int i=n-1;i>=0;i--){
            if(sum+neg[i]>0){
                ans++;;
                sum+=neg[i];
            }
            else{
                break;
            }
        }

        return ans;
    }
};