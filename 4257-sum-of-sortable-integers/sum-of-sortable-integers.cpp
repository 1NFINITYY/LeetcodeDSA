class Solution {
public:

    bool solve(int k,vector<int>& nums,int& n){
        int x=n/k;

        if(k==1){
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1]){
                    return false;
                }
            }
            return true;
        }

        if(k==n){
            int count=0;

            for(int i=0;i<n;i++){
                if(nums[i]>nums[(i+1)%n]) count++;
            }

            if(count>1) return false;
            return true;
        }

        int high=0;
        int low=INT_MAX;

        for(int i=0;i<x;i++){

            int lowcurr=INT_MAX;
            int highcurr=0;
            int countofsmall=0;

            for(int j=0;j<k;j++){
                if(nums[(i*k)+j]>nums[(i*k)+((j+1)%k)]){
                    countofsmall++;
                }
                highcurr=max(highcurr,nums[(i*k)+j]);
                lowcurr=min(lowcurr,nums[(i*k)+j]);
            }
            
            if(countofsmall>1){
                return 0;
            }

            if(high>lowcurr){
                cout<<"working"<<k<<endl;
                return false;
            }

            high=highcurr;
            low=lowcurr;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> divisors;

        for(int i=1;i<n+1;i++){
            if(n%i==0){
                divisors.push_back(i);
            }
        }

        int ans=0;

        for(auto i:divisors){
            if(solve(i,nums,n)){
                ans+=i;
            }
        }

        return ans;
    }
};