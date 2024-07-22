class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int n=nums.size();
        
        int l=0;
        int r=n-1;//it may be inserted at last pos;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(nums[mid]==t) return mid;
            else if(nums[mid]<t){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};