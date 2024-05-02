class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size(),mxans=-1;
        unordered_set<int> s;
        
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            if(s.find(0-nums[i])!=s.end()) mxans=max(mxans,abs(nums[i]));
        }
        return mxans;
        
    }
};