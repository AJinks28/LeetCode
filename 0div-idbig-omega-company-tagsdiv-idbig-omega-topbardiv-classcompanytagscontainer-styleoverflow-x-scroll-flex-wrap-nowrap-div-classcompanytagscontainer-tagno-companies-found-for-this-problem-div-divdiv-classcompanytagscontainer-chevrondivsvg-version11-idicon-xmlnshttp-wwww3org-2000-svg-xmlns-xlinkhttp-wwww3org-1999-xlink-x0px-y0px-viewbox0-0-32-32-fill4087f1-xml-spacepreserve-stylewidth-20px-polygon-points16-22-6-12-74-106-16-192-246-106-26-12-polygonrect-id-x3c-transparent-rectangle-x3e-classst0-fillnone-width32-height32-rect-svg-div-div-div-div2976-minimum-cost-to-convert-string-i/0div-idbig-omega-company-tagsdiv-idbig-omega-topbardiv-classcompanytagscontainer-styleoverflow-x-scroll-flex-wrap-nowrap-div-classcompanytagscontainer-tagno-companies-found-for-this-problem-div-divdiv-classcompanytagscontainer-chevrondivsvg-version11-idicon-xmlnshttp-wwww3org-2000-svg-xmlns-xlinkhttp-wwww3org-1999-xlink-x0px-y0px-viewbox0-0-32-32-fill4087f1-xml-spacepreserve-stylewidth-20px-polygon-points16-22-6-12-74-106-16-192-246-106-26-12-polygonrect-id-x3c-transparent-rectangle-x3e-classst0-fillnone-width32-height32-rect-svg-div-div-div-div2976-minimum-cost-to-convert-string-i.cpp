class Solution {
public:
    long long minimumCost(string src, string t, vector<char>& orig, vector<char>& changed, vector<int>& cost) {
        if(src==t) return 0;
        
        vector<vector<long long>> mat(26,vector<long long>(26,INT_MAX));
        
        
        for(int k=0;k<cost.size();k++){
            mat[orig[k]-'a'][changed[k]-'a']=min(mat[orig[k]-'a'][changed[k]-'a'],(long long)cost[k]);
        }
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        long long sum=0;
        for(int i=0;i<src.size();i++){
            if(src[i]==t[i]) continue;
            if(mat[src[i]-'a'][t[i]-'a']>=INT_MAX) return -1;
            sum+=mat[src[i]-'a'][t[i]-'a'];
        }
        return sum;
    }
};