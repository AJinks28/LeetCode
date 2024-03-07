class Solution {
public:
    //we have to use BFS as we need to traverse simultaneously from all 2s
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int fresh=0;//to check all oranges are rotten or not
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        
        int t=0;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int di=0;di<4;di++){
                    int nr=r+dr[di];
                    int nc=c+dc[di];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1) {
                        q.push({nr,nc});
                        vis[nr][nc]=true;
                        fresh--;
                    }
                }
            }
            t++;
        }
        
        if(fresh>0) return -1;
        if(t==0) return 0;
        return t-1;
        
    }
};