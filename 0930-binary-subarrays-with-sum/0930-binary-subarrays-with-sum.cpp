class Solution {
public:
    int solve(vector<int>& nums, int goal){
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
};