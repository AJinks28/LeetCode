class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        
        for(int i=0;i<n;i++) dp[0][i]=mat[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i-1][j];
                if(j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                if(j<n-1) dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                
                dp[i][j]+=mat[i][j];
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++) res=min(res,dp[n-1][i]);
        
        return res;
    }
};