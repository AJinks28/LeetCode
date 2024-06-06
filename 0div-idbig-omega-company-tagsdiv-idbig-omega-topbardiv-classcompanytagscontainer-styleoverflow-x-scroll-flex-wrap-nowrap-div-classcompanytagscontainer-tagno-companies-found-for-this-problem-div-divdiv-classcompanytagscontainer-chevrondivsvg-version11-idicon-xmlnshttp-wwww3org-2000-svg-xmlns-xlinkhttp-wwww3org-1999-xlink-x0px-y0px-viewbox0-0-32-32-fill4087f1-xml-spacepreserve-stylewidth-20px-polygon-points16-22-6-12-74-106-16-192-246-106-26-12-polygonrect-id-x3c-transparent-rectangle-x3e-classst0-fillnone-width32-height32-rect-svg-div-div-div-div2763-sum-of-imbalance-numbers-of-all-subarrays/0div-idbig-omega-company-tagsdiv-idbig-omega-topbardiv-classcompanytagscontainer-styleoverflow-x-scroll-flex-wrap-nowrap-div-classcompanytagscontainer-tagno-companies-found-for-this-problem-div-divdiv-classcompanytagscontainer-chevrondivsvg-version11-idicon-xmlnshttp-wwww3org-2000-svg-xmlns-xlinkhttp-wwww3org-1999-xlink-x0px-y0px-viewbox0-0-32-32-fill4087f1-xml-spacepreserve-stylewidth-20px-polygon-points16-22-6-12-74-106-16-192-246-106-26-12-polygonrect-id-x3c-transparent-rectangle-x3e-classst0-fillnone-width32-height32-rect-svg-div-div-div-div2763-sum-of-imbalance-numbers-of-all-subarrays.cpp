class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n=nums.size();
        
        int res=0;
        for(int i=0;i<n;i++){
            int curr=0;
            unordered_set<int> s({nums[i]});
            for(int j=i+1;j<n;j++){
                if(s.count(nums[j])) ;
                else if(s.count(nums[j]-1) && s.count(nums[j]+1)) curr--;
                else if(!s.empty() && !s.count(nums[j]-1) && !s.count(nums[j]+1)) curr++;
                s.insert(nums[j]);
                res+=curr;
            }
            
        }
        return res;
    }
};