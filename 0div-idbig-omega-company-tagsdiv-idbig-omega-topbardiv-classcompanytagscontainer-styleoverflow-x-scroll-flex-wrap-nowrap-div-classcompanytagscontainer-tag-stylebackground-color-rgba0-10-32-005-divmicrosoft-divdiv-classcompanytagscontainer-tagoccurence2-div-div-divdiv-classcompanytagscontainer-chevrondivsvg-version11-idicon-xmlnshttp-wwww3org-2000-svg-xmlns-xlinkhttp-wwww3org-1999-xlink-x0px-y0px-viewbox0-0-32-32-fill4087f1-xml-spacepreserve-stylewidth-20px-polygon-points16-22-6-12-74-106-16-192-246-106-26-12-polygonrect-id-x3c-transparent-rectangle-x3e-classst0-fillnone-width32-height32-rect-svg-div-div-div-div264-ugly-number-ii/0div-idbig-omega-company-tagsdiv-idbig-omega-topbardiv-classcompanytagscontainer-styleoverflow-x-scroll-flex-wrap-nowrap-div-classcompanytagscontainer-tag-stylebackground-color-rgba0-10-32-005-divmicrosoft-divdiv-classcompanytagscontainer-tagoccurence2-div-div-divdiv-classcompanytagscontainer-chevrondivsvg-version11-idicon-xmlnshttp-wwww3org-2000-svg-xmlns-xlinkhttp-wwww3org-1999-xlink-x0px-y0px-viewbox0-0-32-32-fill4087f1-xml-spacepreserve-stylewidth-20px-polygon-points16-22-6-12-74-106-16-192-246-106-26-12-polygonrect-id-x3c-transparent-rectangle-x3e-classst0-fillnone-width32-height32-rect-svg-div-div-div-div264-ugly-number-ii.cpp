class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n+1);
        dp[0]=1;
        // if(n==1) return 1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            int i2ugly=dp[i2]*2;
            int i3ugly=dp[i3]*3;
            int i5ugly=dp[i5]*5;
            
            dp[i]=min({i2ugly,i3ugly,i5ugly});
            
            if(dp[i]==i2ugly) i2++;
            if(dp[i]==i3ugly) i3++;
            if(dp[i]==i5ugly) i5++;
        }
        return dp[n-1];
    }
};