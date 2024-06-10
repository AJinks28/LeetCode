class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int> m1,m2;
        for(int i=0;i<n;i++) m2[nums[i]]++;
        
        for(int i=0;i<n;i++){
            m1[nums[i]]++;
            m2[nums[i]]--;
            int x=m1[nums[i]];
            int y=m2[nums[i]];
            
            // cout<<currFreq<<" ";
            if(2*x>(i+1) && 2*y >(n-i-1)) return i;
        }
        return -1;
    }
};