class Solution {
public:
    //SLIDING WINDOW
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n=nums.size();
        int count=0;
        int prod=1;
        for(int l=0,r=0;r<n;r++){
            prod*=nums[r];
            // Shrink the window from the left while the product is greater than or equal to k
            while(prod>=k){
                 // Remove the element at the left pointer from the product
                prod/=nums[l];
                l++;
            }
            // Update the total count by adding the number of valid subarrays with the current window size
            count+= r-l+1;
        }
        return count;
    }
};