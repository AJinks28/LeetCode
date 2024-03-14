class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int m=matrix.size();
        int n=matrix[0].size();
        
        if(j<0 || j>=m) return INT_MAX;
        if(i==0) return dp[i][j]=matrix[0][j];
        
        if(dp[i][j]!=-1e9) return dp[i][j];
        
        int up=solve(i-1,j,matrix,dp);
        int leftD=solve(i-1,j-1,matrix,dp);
        int rightD=solve(i-1,j+1,matrix,dp);
                
        return dp[i][j]=matrix[i][j]+min(up,min(leftD,rightD));
             
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //Variable Start and Variable ending problem
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1e9));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                solve(i,j,matrix,dp);
            }
        }
        int minAns=dp[m-1][0];
        for(int j=0;j<m;j++) minAns=min(minAns,dp[m-1][j]);
        
        return minAns;
    }
};