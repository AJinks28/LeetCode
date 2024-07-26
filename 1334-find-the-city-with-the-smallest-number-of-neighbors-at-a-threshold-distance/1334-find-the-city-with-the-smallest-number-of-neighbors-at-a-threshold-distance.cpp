class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int min_cnt=INT_MAX,city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt) cnt++;
            }
            if(cnt<=min_cnt){
                min_cnt=cnt;
                city=i;
            }
        }
        return city;
    }
};
