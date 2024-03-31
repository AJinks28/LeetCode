class Solution {
public:
    //Sliding Window
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int ans=1; //by default maxFreq will be 1
        long sum=0;
        
        for(int i=0,j=0;j<n;j++){
            sum+=nums[j]; //add right elem
            
            //We want to increase all the numbers in the window to equal A[j],
            //the number of operations needed  is (j - i + 1) * A[j] - sum which should be <= k. 
            //For example, assume the window is [1,2,3], increasing all the numbers to 3 will take
            //3 * 3 - (1 + 2 + 3) operations.
            while((j-i+1)*long(nums[j])-sum>k){ 
                sum-=nums[i];
                i++;
            }
            
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};