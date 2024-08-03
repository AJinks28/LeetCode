class Solution {
public:
    int solve(int mid,vector<int>& nums){
        int cnt=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                cnt++;
                sum=nums[i];
            }
            else sum+=nums[i];
        }
        return cnt+1;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        int l=0,r=0;
        for(int num:nums) {
            l=max(l,num);
            r+=num;
        }
        
        while(l<=r){
            int mid=(l+r)/2;
            if(solve(mid,nums)<=k) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};