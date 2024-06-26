class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m][n-1]=1;
        dp[m-1][n]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){          
                
                int down=dp[i+1][j];
                int right=dp[i][j+1];
                
               int need = min(down,right) - grid[i][j];
                dp[i][j] = (need <= 0) ? 1 : need;
                
            }
        }
        return dp[0][0];
    }
};