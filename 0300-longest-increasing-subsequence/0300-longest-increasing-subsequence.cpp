class Solution {
public:
    int dp[3000][3000];
    int solve(int i,int prev,vector<int>& nums){
        int n=nums.size();
        if(i>=n) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int ans=0;
        if(prev==-1 || nums[i]>nums[prev]){
            ans=max(ans,1+solve(i+1,i,nums));
        }
        ans=max(ans,solve(i+1,prev,nums));
        return dp[i][prev+1]=ans;
            
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};