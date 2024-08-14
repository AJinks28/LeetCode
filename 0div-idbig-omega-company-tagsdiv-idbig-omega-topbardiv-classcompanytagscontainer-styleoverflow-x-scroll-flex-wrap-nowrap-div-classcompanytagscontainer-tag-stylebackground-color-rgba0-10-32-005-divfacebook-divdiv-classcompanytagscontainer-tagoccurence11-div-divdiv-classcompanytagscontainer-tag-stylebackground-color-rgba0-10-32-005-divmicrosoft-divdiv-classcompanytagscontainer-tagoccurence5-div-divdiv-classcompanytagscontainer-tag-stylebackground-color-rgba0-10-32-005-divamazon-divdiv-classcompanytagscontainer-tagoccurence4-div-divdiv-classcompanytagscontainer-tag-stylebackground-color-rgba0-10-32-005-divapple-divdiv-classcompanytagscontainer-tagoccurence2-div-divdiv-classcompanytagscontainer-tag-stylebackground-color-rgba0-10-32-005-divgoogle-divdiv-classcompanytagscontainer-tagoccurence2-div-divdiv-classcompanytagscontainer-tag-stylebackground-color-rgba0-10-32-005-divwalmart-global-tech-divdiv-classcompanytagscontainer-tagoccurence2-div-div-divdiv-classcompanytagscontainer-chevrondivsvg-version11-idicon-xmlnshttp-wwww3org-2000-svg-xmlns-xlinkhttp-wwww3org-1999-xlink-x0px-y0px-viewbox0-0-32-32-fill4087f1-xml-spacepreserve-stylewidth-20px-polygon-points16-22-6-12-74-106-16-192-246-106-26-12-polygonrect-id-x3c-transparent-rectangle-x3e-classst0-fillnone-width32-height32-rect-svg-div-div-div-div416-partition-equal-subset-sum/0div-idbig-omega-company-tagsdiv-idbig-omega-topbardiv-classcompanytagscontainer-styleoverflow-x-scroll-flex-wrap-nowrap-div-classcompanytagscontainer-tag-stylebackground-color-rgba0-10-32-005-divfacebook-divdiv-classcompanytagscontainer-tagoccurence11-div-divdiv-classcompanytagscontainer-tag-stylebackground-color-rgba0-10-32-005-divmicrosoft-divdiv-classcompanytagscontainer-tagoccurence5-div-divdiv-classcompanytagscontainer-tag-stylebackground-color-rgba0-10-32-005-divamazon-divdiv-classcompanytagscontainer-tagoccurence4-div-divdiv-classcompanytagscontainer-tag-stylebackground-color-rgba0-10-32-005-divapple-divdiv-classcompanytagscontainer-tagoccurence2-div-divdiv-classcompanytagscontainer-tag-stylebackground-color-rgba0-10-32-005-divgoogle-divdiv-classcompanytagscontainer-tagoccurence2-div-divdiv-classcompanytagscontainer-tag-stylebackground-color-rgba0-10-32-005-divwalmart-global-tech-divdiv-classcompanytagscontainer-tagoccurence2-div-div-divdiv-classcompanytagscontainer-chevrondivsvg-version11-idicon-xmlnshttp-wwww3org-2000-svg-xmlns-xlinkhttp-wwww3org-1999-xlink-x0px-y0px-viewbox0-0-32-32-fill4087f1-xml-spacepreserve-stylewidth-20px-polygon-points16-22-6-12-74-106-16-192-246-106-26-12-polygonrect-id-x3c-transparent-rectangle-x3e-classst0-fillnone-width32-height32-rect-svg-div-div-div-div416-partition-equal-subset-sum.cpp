class Solution {
public:
    int dp[201][20001];
    bool isSubsetSum(vector<int>& arr, int sum){
        memset(dp,0,sizeof(dp));
        int n=arr.size();
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=sum;j++){
                if(j>=arr[i]) dp[i][j]|=dp[i+1][j-arr[i]];
                dp[i][j]|=dp[i+1][j];
            }
        }
        
        return dp[0][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        
        return isSubsetSum(nums,sum/2);
    }
};