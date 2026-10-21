class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string temp=s;
        sort(temp.begin(),temp.end());

        if(temp==s) return 0;
        if(n==2) return -1;

        int countofstart=0;
        int countoflast=0;

        for(int i=0;i<n;i++){
            if(s[0]==s[i]) countofstart++;
            if(s[n-1]==s[i]) countoflast++;
        }

        if(s[0]==temp[n-1]&&s[n-1]==temp[0]){
            if(countofstart==1&&countoflast==1){
                return 3;
            }
            else{
                return 2;
            }
        }
        
        if(s[0]!=temp[0]&&s[n-1]!=temp[n-1]) return 2;

        return 1;
    }
};
