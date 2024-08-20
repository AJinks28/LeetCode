class Solution {
public:
    int findMax(int mid,vector<vector<int>>& mat){
        int m=mat.size();
        int mx=mat[0][mid],idx=0;
        for(int i=0;i<m;i++) { 
            if(mx<mat[i][mid]){
                mx=mat[i][mid];
                idx=i;
            } 
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        int l=0,r=n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            
            int rmax=findMax(mid,mat);
            
            int left=  mid-1>=0 ? mat[rmax][mid-1] : -1;
            int right= mid+1 <n ? mat[rmax][mid+1] : -1;
            
            if(mat[rmax][mid] > left && mat[rmax][mid] > right)
                return {rmax,mid};
            else if(mat[rmax][mid] < left) r=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
};