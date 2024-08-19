class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,int n){
        if(i==n) return 0;
        if(i>=n) return 1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=1e9;
        if(i!=j) ans=min(ans,solve(i,i,n));
        if(j!=0) ans=min(ans,solve(i+j,j,n));
        
        return dp[i][j]=1+ans;
    }
    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,0,n);
    }
};