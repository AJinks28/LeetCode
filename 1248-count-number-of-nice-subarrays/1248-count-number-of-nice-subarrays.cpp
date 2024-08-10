class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if(k<0) return 0;
        int n=nums.size();
        int cntodd=0;
        
        int i=0,cnt=0;
        for(int j=0;j<n;j++){
            if(nums[j]%2) cntodd++;
            
            while(cntodd>k){
                if(nums[i]%2) cntodd--;
                i++;
            }
            
            cnt+=(j-i+1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
    
};