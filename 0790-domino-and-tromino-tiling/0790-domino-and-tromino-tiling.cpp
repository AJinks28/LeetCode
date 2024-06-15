class Solution {
public:
    
    int MOD=1e9+7;
    int numTilings(int n) {
        
        vector<int> dp(1001);
        dp[0]=1,dp[1]=1,dp[2]=2;
        if(n<3) return dp[n];
        for(int i=3;i<=n;i++) dp[i]=((2*dp[i-1])%MOD+dp[i-3])%MOD;
        
        
        return dp[n]%MOD;
    }
};