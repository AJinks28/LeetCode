class Solution {
public:
    //USING DFS
    bool dfs(int node,int currCol,vector<int>& col,vector<vector<int>>& graph){
        col[node]=currCol;
        
        for(auto adjNode:graph[node]){
            // if uncoloured
            if(col[adjNode]==-1){
                if(dfs(adjNode,!currCol,col,graph)==false) return false;
            }
            // if previously coloured and have the same colour
            else if(col[adjNode]==currCol) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1); //all nodes are not colored yet
        
        //for all connected components
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(i,0,col,graph)==false) return false;
            }
        }
        
        return true;
    }
};