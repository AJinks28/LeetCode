class Solution {
public:
    int dp[1005][2005];
    int solve(int i,int k,vector<vector<int>>& piles){
        int n=piles.size();
        if(i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int nt=solve(i+1,k,piles);
        int t=0;
        int sum=0;
        for(int j=0;j<piles[i].size();j++){
            sum+=piles[i][j];
            if(k-(j+1)>=0) t=max(t,sum+solve(i+1,k-(j+1),piles));
        }
        return dp[i][k]=max(t,nt);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
       return solve(0,k,piles);
    }
};