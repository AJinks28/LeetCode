class Solution {
public:
    bool static comp(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& bt, int t) {
        int n=bt.size();
        
        sort(bt.begin(),bt.end(),comp);
        int ans=0;
        for(int i=0;i<n;i++){
            if(t-bt[i][0]>=0){
                ans+=(bt[i][0]*bt[i][1]);
                t=t-bt[i][0];
            }else{
                ans+=(t*bt[i][1]);
                break;
            }
        }
        return ans;
    }
};