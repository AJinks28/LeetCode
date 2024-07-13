class Solution {
public:
    vector<string> ans;
    void solve(int i,string s,int n){
        if(i==n) {
            ans.push_back(s);
            return;
        }
        solve(i+1,s+"1",n);
        if(s[i-1]=='1'){
            solve(i+1,s+"0",n);
        }
        
    }
    vector<string> validStrings(int n) {
        
        solve(1,"0",n);
        solve(1,"1",n);
        return ans;
    }
};