class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxCnt=0;
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) cnt++;
            else cnt=0;
            
            maxCnt=max(maxCnt,cnt);
        }
        return maxCnt;
    }
};