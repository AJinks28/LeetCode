class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //Fixed Start and Variable ending problem
        // write recursion from 0 to n OR tabulation from n to 0
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        //initializing last row 
        for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                
                int left=dp[i+1][j];
                int right= dp[i+1][j+1];
                
                dp[i][j]=triangle[i][j]+min(left,right);
            }
        }
        return dp[0][0];
    }
};