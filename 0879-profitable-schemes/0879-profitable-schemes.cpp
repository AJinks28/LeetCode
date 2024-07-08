class Solution {
public:
    int dp[105][105][105];
    int M=1e9+7;
    int solve(int i,int prof,int n, int mnp, vector<int>& g, vector<int>& p){
        int m=g.size();
        
        if(i>=m && prof>=mnp && n>=0) return 1;
        if(n<0) return 0;
        if(i>=m) return 0;
        
        if(dp[i][prof][n]!=-1) return dp[i][prof][n];
        
        int t=solve(i+1,min(prof+p[i],mnp),n-g[i],mnp,g,p);
        int nt=solve(i+1,prof,n,mnp,g,p);
        
        return dp[i][prof][n]= (t%M+nt%M)%M;
    }
    int profitableSchemes(int n, int mnp, vector<int>& g, vector<int>& p) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,mnp,g,p);
    }
};