class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> count(26,0);

        for(char i:s){
            count[i-'a']++;
        }

        vector<int> newcount(26,0);
        int c=0;

        bool isvalid;

        vector<int> ans;

        for(char i:s){
            newcount[i-'a']++;
            c++;
            isvalid=1;

            for(int x=0;x<26;x++){
                if(newcount[x]==0) continue;
                if(newcount[x]!=count[x]){
                    isvalid=0;
                }
            }

            if(isvalid){
                ans.push_back(c);
                c=0;
            }
        }

        return ans;
    }
};

