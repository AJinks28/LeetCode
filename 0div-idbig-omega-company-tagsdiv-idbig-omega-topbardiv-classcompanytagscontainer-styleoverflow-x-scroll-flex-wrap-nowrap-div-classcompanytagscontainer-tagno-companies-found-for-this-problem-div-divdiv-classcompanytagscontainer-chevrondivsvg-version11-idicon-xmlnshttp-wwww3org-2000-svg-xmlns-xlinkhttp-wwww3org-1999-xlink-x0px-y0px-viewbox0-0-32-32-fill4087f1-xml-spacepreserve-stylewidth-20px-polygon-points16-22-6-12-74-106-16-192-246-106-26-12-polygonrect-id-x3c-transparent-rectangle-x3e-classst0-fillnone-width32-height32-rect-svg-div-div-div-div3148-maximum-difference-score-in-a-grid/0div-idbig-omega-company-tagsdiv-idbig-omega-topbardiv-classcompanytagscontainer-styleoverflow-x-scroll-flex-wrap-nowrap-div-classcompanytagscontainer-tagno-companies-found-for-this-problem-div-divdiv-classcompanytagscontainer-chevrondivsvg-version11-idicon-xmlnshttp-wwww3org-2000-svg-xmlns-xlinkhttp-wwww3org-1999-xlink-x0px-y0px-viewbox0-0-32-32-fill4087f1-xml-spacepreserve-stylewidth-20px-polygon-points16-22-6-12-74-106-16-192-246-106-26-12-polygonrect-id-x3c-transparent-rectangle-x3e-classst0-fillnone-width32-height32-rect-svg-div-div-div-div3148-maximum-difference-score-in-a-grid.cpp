class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=INT_MIN;
        // vector<vector<int>> dp(m,vector<int>(n));
        
        //dp will store min elem topmost left area
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // dp[i][j]=INT_MAX;
                int mn=INT_MAX;
                if(i>0) mn=min(mn,grid[i-1][j]);//dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(j>0) mn=min(mn,grid[i][j-1]);//dp[i][j]=min(dp[i][j],dp[i][j-1]);
                
                // ans=max(ans,grid[i][j]-dp[i][j]);
                //dp[i][j]=min(dp[i][j],grid[i][j]);
                ans=max(ans,grid[i][j]-mn);
                grid[i][j]=min(grid[i][j],mn);
            }
        }
        return ans;
    }
};