class Solution {
public:
    int solve(int idx,int remain,vector<int>& cost, vector<int>& time,vector<vector<int>> &dp){
        int n=cost.size();
        if(remain<=0) return 0;
        if(idx>=n) return 1e9;
        
        if(dp[idx][remain]!=-1) return dp[idx][remain];
        int paint=cost[idx]+solve(idx+1,remain-time[idx]-1,cost,time,dp);
        int not_paint=solve(idx+1,remain,cost,time,dp);
        
        return dp[idx][remain]=min(paint,not_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,cost,time,dp);
    }
};