class Solution {
public:
    int findDays(int cap,vector<int>& w){
        int d=1;
        int sum=0;
        for(int i=0;i<w.size();i++){
            if(sum+w[i]>cap){
                d++;
                sum=w[i];
            }
            else sum+=w[i];
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l=1,r=0;
        
        for(int &w:weights) {r+=w;l=max(l,w);}
        while(l<r){
            int mid=l+(r-l)/2;
            
            if(findDays(mid,weights)<=days) r=mid;
            else l=mid+1;
        }
        return l;
    }
};