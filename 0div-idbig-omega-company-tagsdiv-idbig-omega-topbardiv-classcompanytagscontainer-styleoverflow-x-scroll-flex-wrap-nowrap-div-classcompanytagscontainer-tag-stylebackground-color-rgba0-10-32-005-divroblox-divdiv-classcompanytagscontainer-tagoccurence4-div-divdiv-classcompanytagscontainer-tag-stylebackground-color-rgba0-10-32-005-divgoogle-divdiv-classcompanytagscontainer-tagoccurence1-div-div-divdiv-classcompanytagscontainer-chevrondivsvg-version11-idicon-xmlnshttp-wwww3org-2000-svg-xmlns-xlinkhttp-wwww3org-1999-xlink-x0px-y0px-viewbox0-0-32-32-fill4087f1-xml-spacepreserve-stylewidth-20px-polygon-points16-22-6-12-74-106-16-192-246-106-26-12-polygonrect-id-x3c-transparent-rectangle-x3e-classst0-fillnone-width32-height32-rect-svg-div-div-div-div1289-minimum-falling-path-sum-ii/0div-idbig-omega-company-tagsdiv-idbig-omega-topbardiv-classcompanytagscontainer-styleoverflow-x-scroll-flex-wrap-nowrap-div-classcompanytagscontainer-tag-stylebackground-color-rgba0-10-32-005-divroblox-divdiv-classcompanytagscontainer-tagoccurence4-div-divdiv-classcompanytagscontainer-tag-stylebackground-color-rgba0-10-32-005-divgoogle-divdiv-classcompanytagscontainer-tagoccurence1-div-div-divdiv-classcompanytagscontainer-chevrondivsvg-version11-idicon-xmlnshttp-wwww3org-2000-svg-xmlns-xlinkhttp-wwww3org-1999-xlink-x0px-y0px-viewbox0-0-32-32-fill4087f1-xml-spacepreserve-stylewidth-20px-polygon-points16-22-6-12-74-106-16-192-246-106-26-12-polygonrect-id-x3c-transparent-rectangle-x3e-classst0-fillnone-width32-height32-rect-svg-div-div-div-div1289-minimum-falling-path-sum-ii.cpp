class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> prev(m+1,INT_MAX),curr(m+1,INT_MAX);

        for(int i=0;i<m;i++){
            prev[m]=min(prev[m],grid[0][i]);
            for(int j=0;j<m;j++){
                if(j!=i) prev[i]=min(prev[i],grid[0][j]);
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=m;j++){
                curr[j]=INT_MAX;
                for(int t=0;t<m;t++){
                if(t!=j) curr[j]=min(curr[j],grid[i][t]+prev[t]);
            }
            }
            prev=curr;
        }
        return prev[m];
    }
};