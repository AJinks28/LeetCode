class Solution {
public:
    
    
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        
      
        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n,0);
        vis[0]=true;
        queue<int> q;
        q.push(0);
        
        int jump=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                if(curr==n-1) return jump;
                vector<int>& temp=mp[arr[curr]];
                temp.push_back(curr-1);
                temp.push_back(curr+1);
                
                for(int t:temp){
                    if(t>=0 && t<n && !vis[t]){
                        vis[t]=true;
                        q.push(t);
                    }
                }
                mp[arr[curr]].clear();
            }
            jump++;
            
        }
        return 0;
    }
};