class Solution {
public:
    
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){//we can buy at idx, either buy or skip
                    int take=-p[i]+dp[i+1][0];//buy
                    int notTake=0+dp[i+1][1];//skip
                    dp[i][j]=max(take,notTake);
                }
                else{//buy==0 we can either sell or skip
                    int take=p[i]+dp[i+1][1];//sell
                    int notTake=0+dp[i+1][0];//skip
                    dp[i][j]=max(take,notTake);
                }
            }
        }
        return dp[0][1];
    }
};