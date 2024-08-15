class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i-1>=0 && mat[i-1][j]>=mat[i][j]) 
                  || (j-1>=0 && mat[i][j-1]>=mat[i][j])
                  || (i+1<m && mat[i+1][j]>=mat[i][j])
                  || (j+1<n && mat[i][j+1]>=mat[i][j]))
                    continue;
                return {i,j};
            }
        }
        return {-1,-1};
    }
};