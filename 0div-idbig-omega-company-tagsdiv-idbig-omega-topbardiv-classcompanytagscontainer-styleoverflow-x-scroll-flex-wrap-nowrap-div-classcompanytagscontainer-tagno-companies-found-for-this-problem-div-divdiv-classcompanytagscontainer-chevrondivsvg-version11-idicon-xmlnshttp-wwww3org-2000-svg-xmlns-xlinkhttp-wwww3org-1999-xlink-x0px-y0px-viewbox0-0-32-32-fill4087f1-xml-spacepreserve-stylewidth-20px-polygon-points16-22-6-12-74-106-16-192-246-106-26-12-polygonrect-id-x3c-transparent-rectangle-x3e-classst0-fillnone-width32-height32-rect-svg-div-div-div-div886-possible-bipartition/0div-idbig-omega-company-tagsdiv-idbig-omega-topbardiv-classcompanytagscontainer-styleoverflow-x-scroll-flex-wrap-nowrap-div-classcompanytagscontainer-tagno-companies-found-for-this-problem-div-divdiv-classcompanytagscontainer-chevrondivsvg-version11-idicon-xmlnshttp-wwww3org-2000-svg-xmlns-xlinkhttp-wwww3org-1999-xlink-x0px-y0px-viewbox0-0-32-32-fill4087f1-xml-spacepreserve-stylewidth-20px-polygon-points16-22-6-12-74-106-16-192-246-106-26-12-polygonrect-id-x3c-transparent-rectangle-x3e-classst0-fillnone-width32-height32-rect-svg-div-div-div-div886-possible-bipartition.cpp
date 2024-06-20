class Solution {
public:
    
    bool bfs(int src,vector<int> adj[],vector<int>& col){
        queue<int> q;
        q.push(src);
        col[src]=0;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto it:adj[curr]){
                if(col[it]==-1){
                    col[it]=!col[curr];
                    q.push(it);
                }
                else if(col[it]==col[curr]) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> adj[n+1];
        for(auto d:dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        
        
        vector<int> col(n+1,-1);
        
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(!bfs(i,adj,col)) return false;
            }
        }
        return true;
    }
};