class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int mx=0,len=0;
        for(char &ch:s){
            if(ch=='(') {
                len++;
                mx=max(mx,len);
            }
            else if(ch==')') len--;
            else continue;
        }
        return mx;
    }
};