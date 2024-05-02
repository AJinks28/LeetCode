class Solution {
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
        if(n==1) return nums[0];
        // if(n==2) return max(nums[0],nums[1]);
        
        
        int prev1=nums[0],prev2=0;
        for(int i=1;i<n-1;i++){
             int take=nums[i];
            if(i>1)  take+=prev2;
            int notake=prev1;

            int curr=max(take,notake);

            prev2=prev1;
            prev1=curr;

        }
        
        int prev3=nums[1],prev4=0;
        for(int i=2;i<n;i++){
             int take=nums[i];
            if(i>1)  take+=prev4;
            int notake=prev3;

            int curr=max(take,notake);

            prev4=prev3;
            prev3=curr;

        }
        return max(prev1,prev3);
    }
};