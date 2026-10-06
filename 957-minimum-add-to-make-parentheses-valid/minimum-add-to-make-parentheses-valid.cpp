class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0;
        int right=0;

        for(auto i:s){
            if(i=='('){
                right++;
            }
            else if(i==')'&&right>0){
                right--;
            }
            else{
                left++;
            }
        }
        return right+left;
    }
};