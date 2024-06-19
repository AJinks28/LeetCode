class Solution {
public:
    int dp[100001][2];
    int solve(int idx,int prev,string& s){
        if(idx>=s.size()) return 0;
        
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        
        int flips=INT_MAX;
        if(prev==1){
            if(s[idx]=='0') {
                flips=min(flips,1+solve(idx+1,1,s));
            }
            else flips=min(flips,solve(idx+1,1,s));
        }
        else{
            if(s[idx]=='0'){
                flips=min(flips,solve(idx+1,0,s));
                
                flips=min(flips,1+solve(idx+1,1,s));
            }
            else{
                flips=min(flips,solve(idx+1,1,s));
                flips=min(flips,1+solve(idx+1,0,s));
            }
        }
        return dp[idx][prev]=flips;
    }
    
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};