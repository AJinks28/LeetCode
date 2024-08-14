class Solution {
public:
    int dp[21][20001];
    int solve(int i,int sum,vector<int>& nums){
        int n=nums.size();
        
        if(i==n && sum==0) return 1;
        if(i==n) return 0;
        
        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000];
        
        int add=solve(i+1,sum-nums[i],nums);
        int minus=solve(i+1,sum+nums[i],nums);
        
        return dp[i][sum+1000]=add+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,target,nums);
    }
};