class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        int n=cust.size();
        
        long long wt=0;
        int curr=0;
        for(int i=0;i<n;i++){
            int arrv=cust[i][0];
            int t=cust[i][1];
            
            curr=max(curr,arrv)+t;
            wt+=(curr-arrv);
        }
        
        return (double) wt/n;
    }
};