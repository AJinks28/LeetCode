class Solution {
public:
    int dp[105][105];
    int solve(int l,int r,vector<int>& cuts){
        if(r-l<2) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        int ans=1e9;
        for(int i=l+1;i<=r-1;i++){
            ans=min(ans, (cuts[r]-cuts[l])+solve(l,i,cuts)+solve(i,r,cuts));
        }
        //(cuts[r]-cuts[l]) is curr len
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        //this will help in calc of len of stick
        cuts.push_back(n);
        cuts.insert(begin(cuts),0);
                        
        int m=cuts.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,m-1,cuts);
    }
};