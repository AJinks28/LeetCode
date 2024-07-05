class Solution {
public:
    int M=1e9+7;
    int numSubseq(vector<int>& nums, int t) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> pow(n,1);
        for(int i=1;i<n;i++) pow[i]=(pow[i-1]*2)%M; 
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            if(nums[l]+nums[r]>t) r--;
            else{
                
                ans=ans%M+pow[r-l];
                l++;
            }
        }
        
        return ans%M;
    }
};