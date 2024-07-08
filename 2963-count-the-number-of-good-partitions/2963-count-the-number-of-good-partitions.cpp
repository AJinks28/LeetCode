class Solution {
public:
    int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int> lastIdx;
        for(int i=0;i<n;i++) lastIdx[nums[i]]=i;
        
        int j=0,res=1;
        
        for(int i=0;i<n;i++){
            if(i>j){
                res*=2;
                res%=M;
            }
            j=max(j,lastIdx[nums[i]]);
        }
        return res%M;
    }
};