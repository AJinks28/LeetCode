class Solution {
public:
    int dir[4] = {-1, 0, 1, 0};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=0;

        while(!q.empty()){
            int wt=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();

            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nr=r+dir[i];
                    int nc=c+dir[j];

                    if(nr<0 || nc<0 || nr>=n || nc>=n || grid[nr][nc]==1)
                        continue;
                    if(wt+1<dist[nr][nc]){
                        dist[nr][nc]=wt+1;
                        q.push({wt+1,{nr,nc}});
                    } 
                }
            }
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1]+1;
    }
};