class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(abs(s[i]-t[i]));
        }
        
        int sum=0,maxLen=0;
        
        for(int i=0,j=0;j<n;j++){
            sum+=nums[j];
            
            while(sum>maxCost){
                sum-=nums[i];
                i++;
            }
            
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};