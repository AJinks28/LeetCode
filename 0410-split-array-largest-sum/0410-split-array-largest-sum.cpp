class Solution {
public:
    int findMinSum(int k,vector<int>& nums){
        int cnt=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>k){
                cnt++;
                sum=nums[i];
            }
            else{sum+=nums[i];}
        }
        return cnt+1;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int l=0,r=0;
        for(int &n:nums) {
            r+=n;
            l=max(l,n);
        }
        int res=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(findMinSum(mid,nums)>k){
                
                l=mid+1;
            }
            else{ res=mid;r=mid-1; }
        }
        return res;
    }
};