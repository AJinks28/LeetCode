class Solution {
public:
    
    int dfs(int curr,int prev,unordered_map<int,vector<int>>& adj,vector<bool>& hasApple){
        
        int childCnt=0;
        for(auto& child:adj[curr]){
            if(child==prev) continue;
            
            childCnt+=dfs(child,curr,adj,hasApple);
            
            
        }
        if(childCnt || hasApple[curr]) return 2+childCnt;
        return childCnt;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=dfs(0,-1,adj,hasApple);
        
        
        return max(dfs(0,-1,adj,hasApple)-2, 0);
    }
};