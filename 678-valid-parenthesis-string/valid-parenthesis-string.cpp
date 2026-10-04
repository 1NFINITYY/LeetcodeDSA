class Solution {
public:

    bool solve(string& s){
        int count=0;
        int star=0;
        for(auto i:s){
            if(i=='('){
                count++;
            }
            else if(i=='*'){
                star++;
            }
            else if(count==0&&i==')'){
                star--;
            }
            else{
                count--;
            }

            if(star<0){
                return false;
            }
        }
        if(count==0||star>=count) return true;
        return false;
    }

    bool checkValidString(string s) {
        bool ans=solve(s);
        string st="";
        for(auto i:s){
            if(i=='*'){
                st=i+st;
            }
            else if(i=='('){
                st=')'+st;
            }
            else{
                st='('+st;
            }
        }
        return ans&&solve(st);
    }
};