class Solution {
public:
    int solve(vector<int>& nums, int goal){//Function for subarray sum <= goal
        if(goal<0) return 0;
        int n=nums.size();
        
        int sum=0,cnt=0;
        for(int i=0,j=0;j<n;j++){
            sum+=nums[j];
            
            
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            
            cnt+=j-i+1;
            
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
    //solving problem for subarraySum less than equal to goal - subarraySum less than equal to goal-1 
};