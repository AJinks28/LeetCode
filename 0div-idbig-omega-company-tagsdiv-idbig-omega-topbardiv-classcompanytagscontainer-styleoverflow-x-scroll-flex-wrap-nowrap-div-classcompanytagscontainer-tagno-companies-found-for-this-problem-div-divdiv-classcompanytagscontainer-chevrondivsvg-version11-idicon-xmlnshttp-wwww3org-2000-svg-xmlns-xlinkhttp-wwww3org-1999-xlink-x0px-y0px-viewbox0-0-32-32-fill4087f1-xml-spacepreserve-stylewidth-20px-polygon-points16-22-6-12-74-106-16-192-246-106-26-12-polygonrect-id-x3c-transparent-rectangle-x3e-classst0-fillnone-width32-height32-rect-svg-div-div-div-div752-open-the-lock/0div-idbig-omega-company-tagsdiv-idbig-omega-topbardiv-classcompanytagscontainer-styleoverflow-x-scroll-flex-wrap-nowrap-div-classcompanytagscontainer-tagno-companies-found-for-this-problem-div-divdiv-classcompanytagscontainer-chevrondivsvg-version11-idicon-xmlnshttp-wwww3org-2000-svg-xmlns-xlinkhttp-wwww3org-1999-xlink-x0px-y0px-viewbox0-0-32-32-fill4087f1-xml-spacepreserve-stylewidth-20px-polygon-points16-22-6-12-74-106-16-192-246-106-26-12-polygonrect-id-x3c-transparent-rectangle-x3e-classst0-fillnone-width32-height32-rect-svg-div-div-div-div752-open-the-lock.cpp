class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // unordered_set<int> dead;
        // for(int i=0;i<deadends.size();i++){
        //     dead.insert(stoi(deadends[i]));
        // }
        
        // target=stoi(target);
        
        unordered_map<string,int>vis;
         for(int i=0;i<deadends.size();i++){
            vis[deadends[i]]=1;
        }
        if (vis.count("0000")) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        vis["0000"]=1;
        
        int ans=INT_MAX;
        while(!q.empty()){
            string curr=q.front().first;
            int currMove=q.front().second;
            q.pop();
            
            if(curr==target)  ans=min(ans,currMove);
            
            
            for(int i=0;i<4;i++){
                string temp1=curr,temp2=curr;
                temp1[i]=(temp1[i]-'0'+1+10)%10+'0';
                // cout<<temp1<<endl;
                if(vis.find(temp1)==vis.end()){
                    vis[temp1]=1;
                    q.push({temp1,currMove+1});
                }
                temp2[i]=(temp2[i]-'0'-1+10)%10+'0';
                // cout<<temp2<<endl;
                 if(vis.find(temp2)==vis.end()){
                    vis[temp2]=1;
                    q.push({temp2,currMove+1});
                }
                // cout<<endl;
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};