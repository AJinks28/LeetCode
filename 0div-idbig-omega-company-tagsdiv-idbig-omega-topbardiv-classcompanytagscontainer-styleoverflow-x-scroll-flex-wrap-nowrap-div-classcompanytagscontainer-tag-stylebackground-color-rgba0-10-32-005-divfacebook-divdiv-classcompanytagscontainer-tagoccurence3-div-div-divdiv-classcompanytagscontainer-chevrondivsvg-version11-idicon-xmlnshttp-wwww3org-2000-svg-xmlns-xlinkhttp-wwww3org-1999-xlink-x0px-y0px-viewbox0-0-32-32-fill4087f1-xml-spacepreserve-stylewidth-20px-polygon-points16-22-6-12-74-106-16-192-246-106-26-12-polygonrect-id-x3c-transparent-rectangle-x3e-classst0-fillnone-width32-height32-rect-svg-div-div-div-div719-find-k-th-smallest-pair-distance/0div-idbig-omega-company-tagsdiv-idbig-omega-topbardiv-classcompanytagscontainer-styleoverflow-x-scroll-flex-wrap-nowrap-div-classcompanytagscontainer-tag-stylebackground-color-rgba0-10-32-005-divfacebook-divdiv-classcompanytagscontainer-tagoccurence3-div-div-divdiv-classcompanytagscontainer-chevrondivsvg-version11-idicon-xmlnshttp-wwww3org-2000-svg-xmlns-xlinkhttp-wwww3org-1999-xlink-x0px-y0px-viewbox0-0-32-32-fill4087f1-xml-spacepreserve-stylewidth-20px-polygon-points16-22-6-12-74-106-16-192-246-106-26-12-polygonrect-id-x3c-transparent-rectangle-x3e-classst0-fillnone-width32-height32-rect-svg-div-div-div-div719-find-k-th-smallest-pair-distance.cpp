class Solution {
public:
    
    int solve(vector<int>& nums,int m){
        int cnt=0;
        int l=0;
        
        for(int r=0;r<nums.size();r++){
            while(nums[r]-nums[l]>m) l++;
            cnt+=(r-l);
        }
        return cnt;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       
        int l=0;
        int h=nums[n-1]-nums[0];
        
        while(l<h){
            int mid=(l+h)/2;
            
            int cnt=solve(nums,mid);
            
            if(cnt<k) l=mid+1;
            else h=mid;
        }
        
        return l;
    }
};