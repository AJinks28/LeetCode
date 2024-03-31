class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size();
        
        int minPos=-1;
        int maxPos=-1;
        int culpritIdx=-1;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]<minK || nums[i]> maxK) //if nums[i] is not in range it is culprit index
                culpritIdx=i;
            
            if(nums[i]==minK) minPos=i;
            if(nums[i]==maxK) maxPos=i;
            
            int temp= min(minPos,maxPos)-culpritIdx;
            ans+= temp>=0 ? temp :0;
        }
        return ans;
    }
};
//https://www.youtube.com/watch?v=z6LwIkEn9qc&t=1660s&ab_channel=codestorywithMIK