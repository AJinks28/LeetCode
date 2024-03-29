class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        
        int lsum=0,rsum=0;
        
        for(int i=0;i<k;i++){
            lsum+=nums[i];
        }
        int maxSum=lsum;
        for(int i=k-1;i>=0;i--){
            
            rsum+=nums[n-k+i];
            lsum-=nums[i];
            maxSum=max(maxSum,lsum+rsum);
        }
        return maxSum;
    }
};