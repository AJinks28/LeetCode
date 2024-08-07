class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        
        int mx=-1,mxIdx=-1;
        for(int i=0;i<n;i++){
            if(mx<dp[i]) { mx=dp[i];mxIdx=i; }
        }
        vector<int> ans;
        ans.push_back(nums[mxIdx]);
        while(hash[mxIdx]!=mxIdx){
            
            mxIdx=hash[mxIdx];
            ans.push_back(nums[mxIdx]);
        }
        return ans;
    }
};