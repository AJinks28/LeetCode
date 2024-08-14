class Solution {
public:
    int dp[301][10001];
    int solve(int i,int amt,vector<int>& coins){
        int n=coins.size();
        if(amt<0) return 0;
        if( i==n && amt==0) return 1;
        if(i==n) return 0;
        
        if(dp[i][amt]!=-1) return dp[i][amt];
        int t=0;
        if(amt>=coins[i]) t=solve(i,amt-coins[i],coins);
        int nt=solve(i+1,amt,coins);
        
        return dp[i][amt]=t+nt;
    }
    int change(int amount, vector<int>& coins) {
         memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};