class Solution {
public:
    bool check(int src,vector<int>& col,int n,vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        col[src]=0;//give color 0 to src node
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto it:graph[curr]){
                //if adjNode is not yet colored, give it a opposite color of current node
                if(col[it]==-1){
                    col[it]=!col[curr];
                    q.push(it);
                }
                //if adjNode is already colored and color is same as of curr node--> NOT bipartite
                else if(col[it]==col[curr])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1); //all nodes are not colored yet
        
        //for all connected components
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(check(i,col,n,graph)==false) return false;
            }
        }
        
        return true;
    }
};