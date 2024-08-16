class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size(),m=goal.size();
        if(n!=m) return false;
        
        for(int i=0;i<n;i++){
            if(s==goal) return true;
            s=s.substr(1,n-1)+s[0];
        }
        return false;
    }
};