class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& t){
        int n=t.size();
        if(i==n){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        ans=min(solve(i+1,j,t),solve(i+1,j+1,t));
        return dp[i][j]=t[i][j]+ans;
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};