class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowSum[i]>colSum[j]){
                    mat[i][j]=colSum[j];
                    rowSum[i]-=colSum[j];
                    colSum[j]=0;
                }else if(rowSum[i]<colSum[j]){
                    mat[i][j]=rowSum[i];
                    colSum[j]-=rowSum[i];
                    rowSum[i]=0;
                }else{
                    mat[i][j]=rowSum[i];
                    rowSum[i]=0;
                    colSum[j]=0;
                }
            }
        }
        return mat;
    }
};