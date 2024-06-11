class Solution {
public:
    
    
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(s1[i]==s2[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
       
    }
};