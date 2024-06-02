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
        vector<vector<int>> dp(n+1,vector<int>(d+1,1001));
        
        dp[n][0]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=d;j++){
                int ans=INT_MAX,maxD=nums[i];
                for(int k=i;k<=n-j;k++){
                    maxD=max(maxD,nums[k]);
                    int res=maxD+dp[k+1][j-1];
                    ans=min(ans,res);
                }
                dp[i][j]=ans;
            }
        }
        
        return dp[0][d];
    }
};