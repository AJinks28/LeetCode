class Solution {
public:
    int dp[13][10001];
    int solve(int i,int amt,vector<int>& coins){
        int n=coins.size();
        if(amt<0) return 1e9;
        if( i==n && amt==0) return 0;
        if(i==n) return 1e9;
        
        if(dp[i][amt]!=-1) return dp[i][amt];
        int t=1e9;
        if(amt>=coins[i]) t=1+solve(i,amt-coins[i],coins);
        int nt=solve(i+1,amt,coins);
        
        return dp[i][amt]=min(t,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res=solve(0,amount,coins);
        return res==1e9 ? -1 : res;
    }
};