class Solution {
public:
    
//     int solve(int idx,int prevArr,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
//         if(idx>=nums1.size()) return 0;
//         if(dp[idx][prevArr]!=-1) return dp[idx][prevArr];
//         int ans=0;
//         if(prevArr==0){
//             ans=max({solve(idx+1,0,nums1,nums2,dp),1+solve(idx+1,1,nums1,nums2,dp),
//                      1+solve(idx+1,2,nums1,nums2,dp)});
//         }
//         else if(prevArr==1){
//             if(nums1[idx-1]<=nums1[idx]) ans=max(ans,1+solve(idx+1,1,nums1,nums2,dp));
//             if(nums1[idx-1]<=nums2[idx]) ans=max(ans,1+solve(idx+1,2,nums1,nums2,dp));
//         }
//         else{
//             if(nums2[idx-1]<=nums1[idx]) ans=max(ans,1+solve(idx+1,1,nums1,nums2,dp));
//             if(nums2[idx-1]<=nums2[idx]) ans=max(ans,1+solve(idx+1,2,nums1,nums2,dp));
//         }
        
//         return dp[idx][prevArr]=ans;
//     }
    
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        
        // return solve(0,0,nums1,nums2,dp);
        
        dp[n][0]=dp[n][1]=dp[n][2]=0;
        for(int idx=n-1;idx>=0;idx--){
            
            for(int j=0;j<3;j++){
                int ans=0;
                if(j==0) ans=max({dp[idx+1][0],1+dp[idx+1][1],1+dp[idx+1][2]});
                else if(j==1){
                     if(idx>0 && nums1[idx-1]<=nums1[idx]) ans=max(ans,1+dp[idx+1][1]);
                     if(idx>0 && nums1[idx-1]<=nums2[idx]) ans=max(ans,1+dp[idx+1][2]);
                }
                else{
                     if(idx>0 && nums2[idx-1]<=nums1[idx]) ans=max(ans,1+dp[idx+1][1]);
                     if(idx>0 && nums2[idx-1]<=nums2[idx]) ans=max(ans,1+dp[idx+1][2]);
                }
                dp[idx][j]=ans;
            }
            
        }
        
        return dp[0][0];
        
    }
};