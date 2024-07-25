class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &c:connections){
            adj[c[0]].push_back({c[1],1});
            adj[c[1]].push_back({c[0],0});
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        
        int cnt=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto &[adjNode,sign]:adj[curr]){
                if(!vis[adjNode]){
                    cnt+=sign;
                    vis[adjNode]=1;
                    q.push(adjNode);
                }
            }
        }
        return cnt;
    }
};