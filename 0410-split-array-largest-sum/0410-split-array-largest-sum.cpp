class Solution {
public:
    bool canSplit(int d,vector<int>& nums,int k){
        int cnt=0;
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            if(totSum+nums[i]<=d) totSum+=nums[i];
            else {
                cnt++;
                totSum=nums[i];
            }
            
        }
        if(cnt+1<=k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        int l=0;
        int r=0;
        
        for (int num : nums) {
            l = max(l,num);
            r += num;
        }
        
        while(l<r){
            int mid=l+(r-l)/2;
            
            if(canSplit(mid,nums,k)){
                r=mid;
                
            }
            else l=mid+1;
        }
        return l;
    }
};