class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m=mat.size();
        int n=mat[0].size();
        
        int l=0,r=m*n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int midVal=mat[mid/n][mid%n];
            if(midVal==t) return true;
            else if(midVal>t) r=mid-1;
            else l=mid+1;
        }
        
        return false;
    }
};