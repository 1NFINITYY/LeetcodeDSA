class Solution {
public:

    void helper(string s,vector<int>& ans,int start){
        int n=s.size();
        int count=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                if(count%2==0){
                    ans[i+start]=0;
                }
                else{
                    ans[i+start]=1;
                }
            }
            else{
                if(count%2==0){
                    ans[i+start]=0;
                }
                else{
                    ans[i+start]=1;
                }
                count--;
            }
            
        }

        return;
    }

    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int> ans(n,-1);
        int count=0;
        string part="";
        int start=0;

        for(int i=0;i<n;i++){
            part+=seq[i];

            if(seq[i]=='('){
                count++;
            }
            else{
                count--;
            }

            if(count==0){
                helper(part,ans,start);
                part="";
                start=i+1;
            }
        }
        return ans;
        
    }
};