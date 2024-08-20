class Solution {
public:
    vector<int> sz,parent;
    
    int findPar(int x){
        if(x==parent[x]) return x;
        return parent[x]=findPar(parent[x]);
    }
    void unionsz(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        
        if(pu==pv) return;
        
        if(sz[pu]>sz[pv]){
            parent[pv]=pu;
            sz[pu]+=sz[pv];
        }
        else{
            parent[pu]=pv;
            sz[pv]+=sz[pu];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        sz.resize(n,1);
        parent.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        
        unordered_map<string, int> mp;
        
        for (int i = 0; i < acc.size(); i++) {
            int m = acc[i].size();

            for (int j = 1; j < m; j++) {
                string email = acc[i][j];
                // string name = acc[i][0];
                
                if (mp.find(email) == mp.end()) {
                    mp[email] = i;
                } else {
                    unionsz(i, mp[email]);
                }
            }
        }
        
        unordered_map<int, vector<string>> mp2;
        for (auto it : mp) {
            string email = it.first;
            int idx = it.second;
            mp2[findPar(idx)].push_back(email);
        }
        
        vector<vector<string>> ans;
        for (auto it : mp2) {
            int idx = it.first;
            
            vector<string> mails = {acc[idx][0]};
            
            mails.insert(mails.end(), it.second.begin(), 
                             it.second.end());
            sort(mails.begin() + 1, mails.end());
            ans.push_back(mails);
        }
        
        return ans;
    }
};