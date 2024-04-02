class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0=0,ans=0;
        for(int i=0,j=0;j<nums.size();j++){
            if(nums[j]==0) cnt0++;
            
            if(cnt0>k){
                if(nums[i]==0)cnt0--;
                i++;
            }
            
            ans=max(ans,j-i+1);
            
        }
        return ans;
    }
};