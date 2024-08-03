class Solution {
public:
    
    long findTime(int k,vector<int>& piles){
        int n=piles.size();
        long totHrs=0;
        
        for(int i=0;i<n;i++){
            long d=piles[i]/k;
            totHrs+=d;
            if(piles[i]%k!=0) totHrs++;
        }
        
        return totHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        
        int mx=-1;
        for(auto &p:piles) mx=max(mx,p);
        
        int l=1,r=mx;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(findTime(mid,piles)<=h) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};