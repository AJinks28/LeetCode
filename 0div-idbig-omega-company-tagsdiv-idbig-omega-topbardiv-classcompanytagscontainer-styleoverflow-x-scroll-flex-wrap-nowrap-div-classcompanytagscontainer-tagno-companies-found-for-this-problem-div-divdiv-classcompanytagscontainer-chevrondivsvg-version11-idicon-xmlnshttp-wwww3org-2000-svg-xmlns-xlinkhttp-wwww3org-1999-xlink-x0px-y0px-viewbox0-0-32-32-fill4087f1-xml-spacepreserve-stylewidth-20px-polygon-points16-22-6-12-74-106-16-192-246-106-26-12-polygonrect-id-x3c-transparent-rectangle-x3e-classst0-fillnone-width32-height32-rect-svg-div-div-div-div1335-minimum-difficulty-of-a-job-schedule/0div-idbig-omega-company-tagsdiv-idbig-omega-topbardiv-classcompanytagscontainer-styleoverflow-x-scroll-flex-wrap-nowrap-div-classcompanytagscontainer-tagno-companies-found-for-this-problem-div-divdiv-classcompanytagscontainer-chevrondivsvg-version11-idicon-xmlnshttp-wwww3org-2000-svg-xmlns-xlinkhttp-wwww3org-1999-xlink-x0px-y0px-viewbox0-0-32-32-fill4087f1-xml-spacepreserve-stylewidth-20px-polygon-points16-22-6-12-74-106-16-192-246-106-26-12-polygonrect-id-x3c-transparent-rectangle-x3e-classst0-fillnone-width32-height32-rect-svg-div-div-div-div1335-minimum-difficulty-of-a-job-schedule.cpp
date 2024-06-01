class Solution {
public:
    int solve(int idx,int d,vector<int>& nums,vector<vector<int>> &dp){
        int n=nums.size();
        if(d==0 && idx==n) return 0;
        if(d==0 || idx==n) return 1001;
        if(dp[idx][d]!=-1) return dp[idx][d];
        
        
        int ans=INT_MAX,maxD=nums[idx];
        for(int i=idx;i<=n-d;i++){
            maxD=max(maxD,nums[i]);
            int res=maxD+solve(i+1,d-1,nums,dp);
            ans=min(ans,res);
            // cout<<ans<<" ";
        }
        return dp[idx][d]=ans;
        
    }
    int minDifficulty(vector<int>& nums, int d) {
        int n=nums.size();
        if(n<d) return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return solve(0,d,nums,dp);
    }
};