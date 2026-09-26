class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        string ans="";
        int n=s.size();
        int m=k.size();

        unordered_map<string,string> mp;

        for(int i=0;i<m;i++){
            mp[k[i][0]]=k[i][1];
        }

        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z') ans+=s[i];

            if(s[i]=='('){
                i++;
                string value="";
                while(s[i]!=')'){
                    value+=s[i];
                    i++;
                }
                string toadd="?";
                if(mp.find(value)!=mp.end()){
                    toadd=mp[value];
                }
                ans+=toadd;
            }
        }

        return ans;
    }
};