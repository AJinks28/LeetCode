class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //Kahn's ALgo
        vector<int> adj[n]; //adj list
        vector<int> indeg(n,0); //indegrees of all nodes
        for(auto edge:prerequisites){
            adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }
        queue<int> q;
        //whenever we get indeg[node]==0 push that in q
        for(int i=0;i<n;i++)
            if(indeg[i]==0) q.push(i);
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        return n==cnt;
    }
};