class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int w,int h,vector<vector<int>>& books,int sw){
        int n=books.size();
        if(i>=n) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        int t=1e9;
        if(w+books[i][0]<=sw){
            t=solve(i+1,w+books[i][0],max(h,books[i][1]),books,sw);
            if(h<books[i][1]) t=t+books[i][1]-h;
        }
        int nt=books[i][1]+solve(i+1,books[i][0],books[i][1],books,sw);
        
        return dp[i][w]=min(t,nt);
    }
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        int n=books.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,books,sw);
    }
};