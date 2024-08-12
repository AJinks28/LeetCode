class Solution {
public:
    int dp[101][101];
//     int solve(int i,int j,vector<vector<int>>& g){
//         int m=g.size();
//         int n=g[0].size();
//         if(g[i][j]==1) return 0;
//         if(i==m-1 && j==n-1) return 1;
//         if(i==m || j==n) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int ans=0;
//         if(i+1<m) ans+=solve(i+1,j,g);
//         if(j+1<n) ans+=solve(i,j+1,g);
        
//         return dp[i][j]=ans;
//     }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        memset(dp,0,sizeof(dp));
        int m=g.size();
        int n=g[0].size();
        if(g[0][0]==1 || g[m-1][n-1]==1) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i == 0 && j == 0) { dp[i][j]=1;continue;}
                int up=0,left=0;
                if(i>0 && g[i-1][j]!=1) up=dp[i-1][j];
                if(j>0 && g[i][j-1]!=1) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        
          
        return dp[m-1][n-1];
    }
};