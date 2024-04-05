class Solution {
public:
    bool check(vector<int>& a) {
        bool flag1=false;
        int n=a.size();
        
        for(int i=1;i<=n;i++){
            
            if(flag1 && a[i-1]>a[i%n]) return false;
            else if(a[i-1]>a[i%n]) flag1=true;
                
        }
        
        return true;
    }
};