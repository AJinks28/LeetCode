class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int op=0,ans=0;
        for(char &ch:s){
            if(ch=='(') op++;
            else op--;
            
            if(op==-1){
                ans++;
                op=0;
            }
        }
        return ans+op;
    }
};