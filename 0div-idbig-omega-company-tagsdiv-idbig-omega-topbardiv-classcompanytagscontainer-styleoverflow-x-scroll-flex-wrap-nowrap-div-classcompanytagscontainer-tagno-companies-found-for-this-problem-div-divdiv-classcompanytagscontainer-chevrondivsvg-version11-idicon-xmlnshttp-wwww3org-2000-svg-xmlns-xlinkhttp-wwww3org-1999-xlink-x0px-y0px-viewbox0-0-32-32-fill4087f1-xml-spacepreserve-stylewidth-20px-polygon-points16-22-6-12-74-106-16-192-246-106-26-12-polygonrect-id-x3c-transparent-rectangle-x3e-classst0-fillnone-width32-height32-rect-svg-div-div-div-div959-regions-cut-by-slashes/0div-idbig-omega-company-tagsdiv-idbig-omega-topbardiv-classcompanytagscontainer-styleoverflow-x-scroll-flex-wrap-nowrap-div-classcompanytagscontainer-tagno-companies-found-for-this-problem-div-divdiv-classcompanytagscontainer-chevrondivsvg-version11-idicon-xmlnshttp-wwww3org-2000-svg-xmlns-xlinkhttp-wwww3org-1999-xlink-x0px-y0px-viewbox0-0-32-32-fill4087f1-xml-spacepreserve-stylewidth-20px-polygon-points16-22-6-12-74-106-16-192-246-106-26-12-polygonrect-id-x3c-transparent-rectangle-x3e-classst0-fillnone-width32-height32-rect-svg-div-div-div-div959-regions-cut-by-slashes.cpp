class Solution {
public:
    
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        vis[i][j]=true;
        int n=grid.size();
        
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==0) dfs(i-1,j,vis,grid);
        if(i+1<n && !vis[i+1][j] && grid[i+1][j]==0) dfs(i+1,j,vis,grid);
        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==0) dfs(i,j-1,vis,grid);
        if(j+1<n && !vis[i][j+1] && grid[i][j+1]==0) dfs(i,j+1,vis,grid);
    }
    
    
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> mat(n*3,vector<int>(n*3,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3+2]=1;
                }
            }
        }
        
        int cnt=0;n=n*3;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<mat[i][j]<<" ";
                if(!vis[i][j] && mat[i][j]==0){
                    cnt++;
                    dfs(i,j,vis,mat);
                }
            }
            // cout<<endl;
        }
        return cnt;
    }
};