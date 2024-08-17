class Solution {
public:
    int strStr(string t, string p) {
        int n=t.size();
        int k=p.size();
        
        for(int i=0;i<=n-k;i++){
            if(t.substr(i,k)==p) return i;
        }
        return -1;
    }
};