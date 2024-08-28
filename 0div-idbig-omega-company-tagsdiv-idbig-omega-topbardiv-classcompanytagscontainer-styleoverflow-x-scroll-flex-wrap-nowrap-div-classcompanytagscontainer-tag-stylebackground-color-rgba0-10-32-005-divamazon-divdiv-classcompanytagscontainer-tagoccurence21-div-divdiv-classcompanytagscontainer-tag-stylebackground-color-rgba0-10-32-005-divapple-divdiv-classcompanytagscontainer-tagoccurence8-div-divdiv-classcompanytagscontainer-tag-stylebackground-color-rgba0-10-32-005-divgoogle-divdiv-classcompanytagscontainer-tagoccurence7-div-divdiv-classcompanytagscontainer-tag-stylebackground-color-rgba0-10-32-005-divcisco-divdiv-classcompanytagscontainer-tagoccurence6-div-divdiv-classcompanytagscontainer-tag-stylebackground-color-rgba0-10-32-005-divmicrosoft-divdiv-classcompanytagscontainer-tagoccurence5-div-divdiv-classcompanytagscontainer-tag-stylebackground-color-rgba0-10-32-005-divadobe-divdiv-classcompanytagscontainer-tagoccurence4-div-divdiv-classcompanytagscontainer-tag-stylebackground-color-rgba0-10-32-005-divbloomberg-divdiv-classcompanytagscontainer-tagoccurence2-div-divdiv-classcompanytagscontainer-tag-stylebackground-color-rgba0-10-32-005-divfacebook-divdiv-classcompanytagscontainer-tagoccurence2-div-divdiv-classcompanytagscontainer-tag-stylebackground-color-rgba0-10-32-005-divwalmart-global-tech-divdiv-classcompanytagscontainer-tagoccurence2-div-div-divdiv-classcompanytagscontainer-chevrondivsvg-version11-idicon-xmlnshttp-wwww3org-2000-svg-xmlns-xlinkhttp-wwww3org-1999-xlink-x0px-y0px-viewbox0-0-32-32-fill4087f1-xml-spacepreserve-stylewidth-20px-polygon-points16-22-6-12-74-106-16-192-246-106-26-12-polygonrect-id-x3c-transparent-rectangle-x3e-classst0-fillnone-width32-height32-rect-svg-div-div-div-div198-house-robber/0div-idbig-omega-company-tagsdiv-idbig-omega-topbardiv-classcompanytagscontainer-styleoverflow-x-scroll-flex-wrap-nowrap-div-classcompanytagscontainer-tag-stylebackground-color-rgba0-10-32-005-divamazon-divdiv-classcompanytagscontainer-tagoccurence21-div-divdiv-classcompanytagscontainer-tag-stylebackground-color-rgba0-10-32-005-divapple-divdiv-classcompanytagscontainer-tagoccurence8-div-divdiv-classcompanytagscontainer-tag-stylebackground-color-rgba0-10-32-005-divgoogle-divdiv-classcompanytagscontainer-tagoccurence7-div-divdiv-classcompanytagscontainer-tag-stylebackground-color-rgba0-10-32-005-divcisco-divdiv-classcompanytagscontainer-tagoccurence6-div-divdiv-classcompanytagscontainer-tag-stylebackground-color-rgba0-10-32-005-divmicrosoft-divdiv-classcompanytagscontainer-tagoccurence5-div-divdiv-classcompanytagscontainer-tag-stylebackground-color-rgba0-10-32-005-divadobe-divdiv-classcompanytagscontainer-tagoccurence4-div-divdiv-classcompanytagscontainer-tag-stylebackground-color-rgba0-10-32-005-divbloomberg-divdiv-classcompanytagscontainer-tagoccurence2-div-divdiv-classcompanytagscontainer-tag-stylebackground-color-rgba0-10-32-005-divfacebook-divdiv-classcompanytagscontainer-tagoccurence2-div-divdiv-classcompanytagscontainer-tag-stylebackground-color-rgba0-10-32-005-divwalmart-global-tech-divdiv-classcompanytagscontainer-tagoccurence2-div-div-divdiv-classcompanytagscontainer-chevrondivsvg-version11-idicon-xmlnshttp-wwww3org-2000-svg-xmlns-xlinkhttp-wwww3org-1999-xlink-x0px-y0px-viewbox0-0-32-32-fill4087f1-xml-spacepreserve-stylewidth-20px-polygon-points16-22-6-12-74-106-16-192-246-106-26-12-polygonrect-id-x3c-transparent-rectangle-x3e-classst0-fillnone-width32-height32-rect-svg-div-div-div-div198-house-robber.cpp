class Solution {
public:
    int dp[101];
    int solve(int i,vector<int>& nums){
        int n=nums.size();
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        ans=max(ans,nums[i]+solve(i+2,nums));
        ans=max(ans,solve(i+1,nums));
        
        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};