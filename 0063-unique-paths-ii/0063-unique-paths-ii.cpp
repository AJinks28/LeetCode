class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,vector<vector<int>>& g){
        int m=g.size();
        int n=g[0].size();
        if(g[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(i==m || j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(i+1<m) ans+=solve(i+1,j,g);
        if(j+1<n) ans+=solve(i,j+1,g);
        
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,g);
    }
};