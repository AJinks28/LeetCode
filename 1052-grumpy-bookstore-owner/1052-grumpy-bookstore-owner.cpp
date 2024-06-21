class Solution {
public:
    
   
    int maxSatisfied(vector<int>& cust, vector<int>& g, int m) {
        int n=cust.size();
        
        //adding all non-grumpy i.e. g[i]=0 to ans because they are in our final solution any how
        int ans=0;
        for(int i=0;i<n;i++){
            if(g[i]==0) {
                ans+=cust[i];
                cust[i]=0;//making them 0 to avoid while sliding window
            }
        }
        
        //simple sliding window
        int i=0;
        int mx=0,temp=0;
        for(int j=0;j<n;j++){
            temp+=cust[j];
            if(j-i+1==m){
                mx=max(mx,temp);
                temp-=cust[i];
                i++;
            }
        }
        return ans+mx;
    }
};