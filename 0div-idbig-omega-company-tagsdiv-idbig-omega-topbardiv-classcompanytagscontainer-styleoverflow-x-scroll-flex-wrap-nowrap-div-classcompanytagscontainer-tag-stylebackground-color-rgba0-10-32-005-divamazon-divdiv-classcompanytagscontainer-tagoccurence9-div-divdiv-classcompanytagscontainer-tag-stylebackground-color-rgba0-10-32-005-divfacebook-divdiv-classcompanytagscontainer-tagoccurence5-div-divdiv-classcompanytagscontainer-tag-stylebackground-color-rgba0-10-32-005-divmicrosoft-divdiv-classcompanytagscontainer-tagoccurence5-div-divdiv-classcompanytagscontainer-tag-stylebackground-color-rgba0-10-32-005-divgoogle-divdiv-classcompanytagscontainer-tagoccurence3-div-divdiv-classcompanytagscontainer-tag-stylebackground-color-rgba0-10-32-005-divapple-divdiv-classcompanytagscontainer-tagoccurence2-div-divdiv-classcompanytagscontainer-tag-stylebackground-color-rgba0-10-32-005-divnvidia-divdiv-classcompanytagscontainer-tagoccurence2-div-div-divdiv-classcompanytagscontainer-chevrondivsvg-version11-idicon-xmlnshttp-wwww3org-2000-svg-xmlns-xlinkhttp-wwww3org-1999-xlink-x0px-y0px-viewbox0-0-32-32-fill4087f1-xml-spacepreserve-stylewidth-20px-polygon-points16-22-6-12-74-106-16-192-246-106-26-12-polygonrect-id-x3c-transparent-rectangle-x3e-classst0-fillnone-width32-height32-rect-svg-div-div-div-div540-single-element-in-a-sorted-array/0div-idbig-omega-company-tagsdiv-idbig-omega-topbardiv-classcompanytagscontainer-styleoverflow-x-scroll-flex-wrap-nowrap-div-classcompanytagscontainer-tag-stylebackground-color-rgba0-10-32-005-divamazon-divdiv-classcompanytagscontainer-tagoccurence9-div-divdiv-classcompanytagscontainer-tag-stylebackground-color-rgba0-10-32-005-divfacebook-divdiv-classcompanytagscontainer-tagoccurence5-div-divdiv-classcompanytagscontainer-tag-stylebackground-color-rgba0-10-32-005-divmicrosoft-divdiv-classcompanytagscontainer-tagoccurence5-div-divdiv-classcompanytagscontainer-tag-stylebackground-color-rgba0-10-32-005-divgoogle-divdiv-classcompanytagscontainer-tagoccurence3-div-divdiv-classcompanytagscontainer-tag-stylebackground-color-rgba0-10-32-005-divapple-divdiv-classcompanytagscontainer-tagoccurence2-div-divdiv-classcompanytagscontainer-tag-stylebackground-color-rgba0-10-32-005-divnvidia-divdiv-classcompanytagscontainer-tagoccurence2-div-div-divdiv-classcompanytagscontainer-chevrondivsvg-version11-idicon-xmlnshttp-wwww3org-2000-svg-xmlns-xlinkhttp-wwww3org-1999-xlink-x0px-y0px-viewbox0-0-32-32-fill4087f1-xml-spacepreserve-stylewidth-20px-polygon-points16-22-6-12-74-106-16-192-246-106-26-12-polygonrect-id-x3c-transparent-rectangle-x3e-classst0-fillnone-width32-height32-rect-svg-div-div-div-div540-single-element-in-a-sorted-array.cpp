class Solution {
public:
    //if we take any element at an even index (0-indexed), the next element should be the same
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        int l=0,r=n-1;
        
        while(l<r){
            int mid=(l+r)/2;
            if(mid%2==1) mid--;
            if(nums[mid]==nums[mid+1]) l=mid+2;
            else r=mid;
        }
        return nums[l];
    }
    
    // index: 0 1 2 3 4 5 6 7 8
    // nums:  1 1 2 3 3 4 4 8 8
};