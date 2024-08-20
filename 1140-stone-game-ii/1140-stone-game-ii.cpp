class Solution {
public:
    int dp[2][101][101];
    int solve(int i,int A,int M,vector<int>& p){
        int n=p.size();
        
        if(i>=n) return 0;
        
        if(dp[A][i][M]!=-1) return dp[A][i][M];
        int ansA=0,ansB=INT_MAX,sum=0;
        for(int X=1;X<=min(2*M,n-i);X++){
            sum+=p[i+X-1];
            if(A==1){
                ansA=max(ansA,sum+solve(i+X,0,max(M,X),p));
            }else{
                ansB=min(ansB,solve(i+X,1,max(M,X),p));
            }
        }
        return dp[A][i][M]= (A==1) ? ansA : ansB;
        
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1,piles);
    }
};