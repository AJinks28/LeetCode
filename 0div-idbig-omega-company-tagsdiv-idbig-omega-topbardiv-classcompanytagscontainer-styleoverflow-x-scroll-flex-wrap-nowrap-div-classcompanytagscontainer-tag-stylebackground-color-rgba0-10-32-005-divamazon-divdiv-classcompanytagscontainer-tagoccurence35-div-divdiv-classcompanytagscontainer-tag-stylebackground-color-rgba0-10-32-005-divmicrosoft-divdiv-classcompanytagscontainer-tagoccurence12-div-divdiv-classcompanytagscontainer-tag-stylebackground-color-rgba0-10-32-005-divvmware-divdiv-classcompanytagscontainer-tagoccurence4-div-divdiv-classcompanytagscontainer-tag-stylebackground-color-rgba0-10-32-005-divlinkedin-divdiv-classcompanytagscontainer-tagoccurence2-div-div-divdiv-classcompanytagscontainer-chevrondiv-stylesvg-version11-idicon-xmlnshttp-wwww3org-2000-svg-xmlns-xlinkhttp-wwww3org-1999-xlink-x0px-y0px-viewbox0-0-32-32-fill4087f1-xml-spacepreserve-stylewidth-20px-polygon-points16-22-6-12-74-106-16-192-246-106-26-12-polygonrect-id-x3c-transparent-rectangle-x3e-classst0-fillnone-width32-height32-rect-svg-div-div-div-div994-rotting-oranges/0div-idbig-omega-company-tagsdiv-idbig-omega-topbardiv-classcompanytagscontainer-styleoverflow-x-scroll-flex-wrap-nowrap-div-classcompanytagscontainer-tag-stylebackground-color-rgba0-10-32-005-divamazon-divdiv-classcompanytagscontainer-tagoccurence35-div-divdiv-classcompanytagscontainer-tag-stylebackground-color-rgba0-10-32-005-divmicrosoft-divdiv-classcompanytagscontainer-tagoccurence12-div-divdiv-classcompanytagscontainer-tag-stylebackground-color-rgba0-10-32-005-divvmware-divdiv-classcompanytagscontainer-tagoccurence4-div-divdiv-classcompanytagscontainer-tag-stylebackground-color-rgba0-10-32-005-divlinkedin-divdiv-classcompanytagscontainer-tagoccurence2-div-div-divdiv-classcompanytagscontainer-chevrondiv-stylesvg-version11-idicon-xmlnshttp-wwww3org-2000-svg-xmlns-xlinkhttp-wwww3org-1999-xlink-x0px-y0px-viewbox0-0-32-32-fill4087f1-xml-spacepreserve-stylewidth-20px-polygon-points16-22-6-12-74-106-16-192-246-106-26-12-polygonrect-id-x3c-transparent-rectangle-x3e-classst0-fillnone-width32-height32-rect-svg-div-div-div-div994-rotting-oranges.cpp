class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //striver wala solution
         if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), t = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++; //total oranges
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int sz = q.size();
            cnt += sz; //our count of rotten oranges
            while(sz--){
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; ++i){
                    int nr = r + dr[i], nc = c + dc[i];
                    if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            if(!q.empty()) t++;//if q is empty at last we will not add in t
        }
        
        return tot == cnt ? t : -1;
    }
};