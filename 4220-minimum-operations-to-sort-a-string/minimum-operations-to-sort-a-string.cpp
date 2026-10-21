class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int star=INT_MAX;
        int en=INT_MIN;

        int countofstart=0;
        int countoflast=0;
        int count=0;

        for(int i=0;i<n;i++){
            star=min(star,s[i]-'a');
            en=max(en,s[i]-'a');
            if(s[0]==s[i]) countofstart++;
            if(s[n-1]==s[i]) countoflast++;
            if(i+1<n&&s[i]>s[i+1]) count++;
        }
        if(count==0) return 0;
        if(n==2) return -1;

        char starti = 'a' + star;
        char endi = 'a' + en;

        if(s[0]==endi&&s[n-1]==starti){
            if(countofstart==1&&countoflast==1){
                return 3;
            }
            else{
                return 2;
            }
        }
        
        if(s[0]!=starti&&s[n-1]!=endi) return 2;

        return 1;
    }
};
