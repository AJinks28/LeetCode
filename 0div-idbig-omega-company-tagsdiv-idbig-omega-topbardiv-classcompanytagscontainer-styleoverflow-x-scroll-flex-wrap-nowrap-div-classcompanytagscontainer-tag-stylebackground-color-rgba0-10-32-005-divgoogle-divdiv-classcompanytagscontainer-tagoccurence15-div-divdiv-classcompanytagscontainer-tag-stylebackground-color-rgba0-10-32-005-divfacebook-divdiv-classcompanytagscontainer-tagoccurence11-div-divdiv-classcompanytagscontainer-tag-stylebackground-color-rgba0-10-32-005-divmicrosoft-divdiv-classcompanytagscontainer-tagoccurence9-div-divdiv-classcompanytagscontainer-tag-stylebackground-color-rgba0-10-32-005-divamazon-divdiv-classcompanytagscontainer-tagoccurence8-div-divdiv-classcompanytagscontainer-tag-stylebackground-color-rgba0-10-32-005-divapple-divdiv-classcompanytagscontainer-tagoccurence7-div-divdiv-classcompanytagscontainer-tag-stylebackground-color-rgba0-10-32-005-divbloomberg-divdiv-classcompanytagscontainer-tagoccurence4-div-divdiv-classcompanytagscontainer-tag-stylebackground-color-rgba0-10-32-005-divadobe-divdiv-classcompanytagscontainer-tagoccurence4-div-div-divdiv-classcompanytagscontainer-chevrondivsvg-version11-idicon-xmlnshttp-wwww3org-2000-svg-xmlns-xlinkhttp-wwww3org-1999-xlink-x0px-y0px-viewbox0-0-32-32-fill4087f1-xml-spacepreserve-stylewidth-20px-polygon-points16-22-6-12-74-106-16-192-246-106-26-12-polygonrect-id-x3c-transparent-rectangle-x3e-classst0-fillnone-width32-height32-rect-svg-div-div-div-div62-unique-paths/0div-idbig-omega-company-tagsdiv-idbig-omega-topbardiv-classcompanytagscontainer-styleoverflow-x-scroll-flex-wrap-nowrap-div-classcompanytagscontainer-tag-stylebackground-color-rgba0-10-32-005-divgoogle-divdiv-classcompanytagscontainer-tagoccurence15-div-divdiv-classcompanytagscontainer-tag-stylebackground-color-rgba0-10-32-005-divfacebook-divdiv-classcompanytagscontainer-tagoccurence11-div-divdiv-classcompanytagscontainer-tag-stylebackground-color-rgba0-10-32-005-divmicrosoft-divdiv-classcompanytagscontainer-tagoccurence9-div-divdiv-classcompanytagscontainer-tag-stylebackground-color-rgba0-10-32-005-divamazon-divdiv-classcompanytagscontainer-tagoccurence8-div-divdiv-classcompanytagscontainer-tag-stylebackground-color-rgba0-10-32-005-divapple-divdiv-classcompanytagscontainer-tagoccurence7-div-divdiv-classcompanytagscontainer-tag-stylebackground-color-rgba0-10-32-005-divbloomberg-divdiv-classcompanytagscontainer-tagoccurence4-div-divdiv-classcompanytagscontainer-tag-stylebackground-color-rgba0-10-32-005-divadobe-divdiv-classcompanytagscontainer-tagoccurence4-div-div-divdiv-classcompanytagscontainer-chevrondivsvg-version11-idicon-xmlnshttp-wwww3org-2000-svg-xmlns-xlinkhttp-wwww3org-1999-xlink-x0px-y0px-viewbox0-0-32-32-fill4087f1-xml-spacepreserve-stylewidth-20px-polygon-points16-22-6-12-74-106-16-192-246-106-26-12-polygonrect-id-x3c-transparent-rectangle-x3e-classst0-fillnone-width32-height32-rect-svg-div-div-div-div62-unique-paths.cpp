class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                 int ans=0;
                if(i+1<m) ans+=dp[i+1][j];
                if(j+1<n) ans+=dp[i][j+1];
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};