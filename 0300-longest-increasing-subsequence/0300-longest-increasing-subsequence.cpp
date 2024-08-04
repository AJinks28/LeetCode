class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> nxt(n+1,0), curr(n+1,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                 if(prev==-1 || nums[ind]>nums[prev]){
                    curr[prev+1]=max(curr[prev+1],1+nxt[ind+1]);
                }
                curr[prev+1]=max(curr[prev+1],nxt[prev+1]);
            }
            nxt=curr;
        }
        
        return nxt[0];
    }
};