class Solution {
public:
    //Sliding Window template 2
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        long sum=0;
        int i=0,j=0;
        for(;j<n;j++){
            sum+=nums[j]; //add right elem
            
            //We want to increase all the numbers in the window to equal A[j],
            //the number of operations needed  is (j - i + 1) * A[j] - sum which should be <= k. 
            //For example, assume the window is [1,2,3], increasing all the numbers to 3 will take
            //3 * 3 - (1 + 2 + 3) operations.
            if((j-i+1)*long(nums[j])-sum>k){ 
                //we GROW the window when it's valid, and SHIFT the window when it's invalid.
                sum-=nums[i];
                i++;
            }
            
        }
        return j-i;
    }
};