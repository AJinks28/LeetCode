class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt0=0;
        
        int i=0,ans=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0) cnt0++;
            if(cnt0>k){
                if(nums[i]==0) cnt0--;
                i++;
            }
            
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};