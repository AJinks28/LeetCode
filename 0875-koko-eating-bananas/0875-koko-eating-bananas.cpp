class Solution {
public:
    int solvek(int k,vector<int>& piles){
        int n=piles.size();
        int totHrs=0;
        
        for(int i=0;i<n;i++){
            totHrs+=ceil((double)piles[i]/(double)k);
        }
        
        return totHrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        
        int l=1,r=1;
        for(int p:piles) r=max(r,p);
        // int ans=n;
        while(l<r){
            int mid=l+(r-l)/2;
            
            if(solvek(mid,piles)<=h){
                // ans=mid;
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};