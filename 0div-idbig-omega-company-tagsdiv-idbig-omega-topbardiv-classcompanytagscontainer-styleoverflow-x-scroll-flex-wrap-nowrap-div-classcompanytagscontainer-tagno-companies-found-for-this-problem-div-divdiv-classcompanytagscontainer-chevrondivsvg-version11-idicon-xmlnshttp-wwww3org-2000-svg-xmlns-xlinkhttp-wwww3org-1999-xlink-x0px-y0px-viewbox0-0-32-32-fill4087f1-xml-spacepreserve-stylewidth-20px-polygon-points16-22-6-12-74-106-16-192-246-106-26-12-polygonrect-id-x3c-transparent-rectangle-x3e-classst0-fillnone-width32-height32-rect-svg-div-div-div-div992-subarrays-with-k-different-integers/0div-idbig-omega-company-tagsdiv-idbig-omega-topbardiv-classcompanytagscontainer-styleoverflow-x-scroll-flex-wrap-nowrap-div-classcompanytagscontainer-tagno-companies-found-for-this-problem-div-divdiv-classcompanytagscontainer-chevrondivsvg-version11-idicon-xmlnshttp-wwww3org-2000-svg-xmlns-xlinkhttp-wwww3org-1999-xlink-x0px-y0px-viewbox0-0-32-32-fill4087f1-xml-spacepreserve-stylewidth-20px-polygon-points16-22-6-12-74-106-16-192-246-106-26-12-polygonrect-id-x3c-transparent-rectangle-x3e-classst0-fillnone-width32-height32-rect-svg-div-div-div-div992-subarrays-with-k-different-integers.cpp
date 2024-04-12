class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int,int> mp;
        
        int res=0;
        for(int i=0,j=0;j<n;j++){
            mp[nums[j]]++;
            
            // if(mp.size()==k) res++;
            
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            
            res+=j-i+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};