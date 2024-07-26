class Solution {
public:
    vector<int> dir={0,1,0,-1,0};
    void solve(vector<vector<char>>& board) {
         int m=board.size();
        int n=board[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            if(board[i][0]=='O') {q.push({i,0}); vis[i][0]=true;}
            if(board[i][n-1]=='O') {q.push({i,n-1}); vis[i][n-1]=true;}
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') {q.push({0,j}); vis[0][j]=true;}
            if(board[m-1][j]=='O') {q.push({m-1,j}); vis[m-1][j]=true;}
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            // vis[r][c]=true;
            q.pop();
            // board[r][c]='X';
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];

                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc] || board[nr][nc]=='X') continue;
                vis[nr][nc]=true;
                q.push({nr,nc});
            }
            

        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==false && board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};