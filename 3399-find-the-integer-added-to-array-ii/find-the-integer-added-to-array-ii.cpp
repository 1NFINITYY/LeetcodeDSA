class Solution {
public:

    bool solve(vector<int>& nums1,vector<int>& nums2,int value,int &n){
        int count=0;
        int i=0;
        int j=0;

        while(i<n&&j<n-2){
            if(nums1[i]-value==nums2[j]){
                i++;
                j++;
                count++;
            }
            else{
                i++;
            }
        }
        if(count==n-2){
            return true;
        }
        return false;
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        if(n==3){
            return nums2[0]-nums1[2];
        }

        vector<int> values;

        if(nums1[0]-nums2[0]==nums1[1]-nums2[1]){
            values.push_back(nums1[0]-nums2[0]);
        }
        if(nums1[0]-nums2[0]==nums1[2]-nums2[1]){
            values.push_back(nums1[0]-nums2[0]);
        }
        if(nums1[0]-nums2[0]==nums1[3]-nums2[1]){
            values.push_back(nums1[0]-nums2[0]);
        }
        if(nums1[1]-nums2[0]==nums1[2]-nums2[1]){
            values.push_back(nums1[1]-nums2[0]);
        }
        if(nums1[1]-nums2[0]==nums1[3]-nums2[1]){
            values.push_back(nums1[1]-nums2[0]);
        }
        if(nums1[2]-nums2[0]==nums1[3]-nums2[1]){
            values.push_back(nums1[2]-nums2[0]);
        }

        int ans=INT_MAX;
        int x=values.size();

        for(int i=0;i<x;i++){
            if(solve(nums1,nums2,values[i],n)){
                ans=min(ans,-1*values[i]);
            }
        }

        return ans;

    }
};


