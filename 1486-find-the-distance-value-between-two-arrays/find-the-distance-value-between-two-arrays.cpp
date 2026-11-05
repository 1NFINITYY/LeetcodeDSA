class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();

        int ans=0;
        int value;

        for(auto i:arr1){
            ans++;
            for(auto j:arr2){
                value=abs(i-j);
                if(value<=d){
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};
