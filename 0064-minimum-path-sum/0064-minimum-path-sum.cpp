class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& g){
        int m=g.size();
        int n=g[0].size();
        
        
        if(i==m-1 && j==n-1){ return g[m-1][n-1];}
        if(i>=m || j>=n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        if(i+1<m) ans=min(ans,solve(i+1,j,g)+g[i][j]);
        if(j+1<n) ans=min(ans,solve(i,j+1,g)+g[i][j]);
        
        return dp[i][j]=ans;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};