class Solution {
public:
    vector<int> dr={0,1,0,-1};
    vector<int> dc={1,0,-1,0};
    void dfs(int i,int j,int& r2,int& c2,vector<vector<int>>& land,vector<vector<int>>& vis){
        int m=land.size();
        int n=land[0].size();
        vis[i][j]=1;
        
        r2=max(r2,i);
        c2=max(c2,j);
        
        for(int k=0;k<4;k++){
            int di=i+dr[k];
            int dj=j+dc[k];
            
            if(di>=0 && dj>=0 && di<m && dj<n && !vis[di][dj] && land[di][dj]) dfs(di,dj,r2,c2,land,vis);
        }
        
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m=land.size();
        int n=land[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && land[i][j]==1){
                    int row1=i,col1=j,row2=0,col2=0;
                    dfs(row1,col1,row2,col2,land,vis);
                    ans.push_back({row1,col1,row2,col2});
                }
            }
        }
        return ans;
    }
};