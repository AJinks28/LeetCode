class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(src);
        vector<int> vis(n,0);
        vis[src]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            if(curr==dest) return true;
            
            for(auto adjNode:adj[curr]){
                if(!vis[adjNode]) q.push(adjNode);
            }
        }
        
        return false;
    }
};