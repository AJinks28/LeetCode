class Solution {
public:
    vector<int> parent;
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionBySz(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv) return;
        parent[max(pu,pv)]=min(pu,pv);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26,0);
        for(int i=0;i<26;i++) parent[i]=i;
        
        for(int i=0;i<s1.size();i++){
            unionBySz(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=findPar(baseStr[i]-'a')+'a';
        }
        return baseStr;
    }
};