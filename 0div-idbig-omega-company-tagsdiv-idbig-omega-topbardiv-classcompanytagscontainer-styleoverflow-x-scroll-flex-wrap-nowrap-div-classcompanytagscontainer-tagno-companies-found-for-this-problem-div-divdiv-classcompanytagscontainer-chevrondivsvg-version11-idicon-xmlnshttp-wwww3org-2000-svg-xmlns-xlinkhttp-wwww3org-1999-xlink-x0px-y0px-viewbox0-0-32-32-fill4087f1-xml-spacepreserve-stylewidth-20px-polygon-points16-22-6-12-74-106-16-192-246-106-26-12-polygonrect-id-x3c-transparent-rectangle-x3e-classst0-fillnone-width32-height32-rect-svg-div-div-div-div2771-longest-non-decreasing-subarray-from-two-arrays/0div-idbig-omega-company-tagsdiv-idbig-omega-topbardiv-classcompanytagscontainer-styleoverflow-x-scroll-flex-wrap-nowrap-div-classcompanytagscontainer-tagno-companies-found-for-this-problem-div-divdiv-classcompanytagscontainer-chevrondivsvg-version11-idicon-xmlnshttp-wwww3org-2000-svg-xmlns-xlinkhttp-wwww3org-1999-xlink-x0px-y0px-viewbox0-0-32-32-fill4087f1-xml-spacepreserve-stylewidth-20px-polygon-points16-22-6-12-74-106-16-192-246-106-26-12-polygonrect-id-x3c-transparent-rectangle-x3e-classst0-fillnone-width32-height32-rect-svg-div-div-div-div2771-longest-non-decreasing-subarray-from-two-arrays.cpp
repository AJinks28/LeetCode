class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        
        vector<int> dp1(n+1,1),dp2(n+1,1);
        int maxLen=1;
        for(int i=1;i<n;i++){
            if(nums1[i]>=nums1[i-1]) dp1[i]=max(dp1[i],1+dp1[i-1]);
            if(nums1[i]>=nums2[i-1]) dp1[i]=max(dp1[i],1+dp2[i-1]);
            if(nums2[i]>=nums1[i-1]) dp2[i]=max(dp2[i],1+dp1[i-1]);
            if(nums2[i]>=nums2[i-1]) dp2[i]=max(dp2[i],1+dp2[i-1]);
            maxLen=max({maxLen,dp1[i],dp2[i]});
        }
        return maxLen;
    }
};