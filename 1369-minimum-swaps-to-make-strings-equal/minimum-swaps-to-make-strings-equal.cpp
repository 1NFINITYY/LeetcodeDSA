class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s1.size();
        int ans=0;
        vector<bool> vis(n,0);

        vector<int> count(26,0);

        for(int i=0;i<n;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(count[i]%2==1){
                return -1;
            }
        }

        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            if(vis[i]==false){
                bool presentsame=false;
                int pos;
                for(int j=i+1;j<n;j++){
                    if(s1[i]==s1[j]&&s2[i]==s2[j]){
                        presentsame=true;
                        pos=j;
                        break;
                    }
                }
                if(presentsame==true){
                    vis[i]=true;
                    vis[pos]=true;
                }
                ans+=1;
            }
        }
        return ans;
    }
};
