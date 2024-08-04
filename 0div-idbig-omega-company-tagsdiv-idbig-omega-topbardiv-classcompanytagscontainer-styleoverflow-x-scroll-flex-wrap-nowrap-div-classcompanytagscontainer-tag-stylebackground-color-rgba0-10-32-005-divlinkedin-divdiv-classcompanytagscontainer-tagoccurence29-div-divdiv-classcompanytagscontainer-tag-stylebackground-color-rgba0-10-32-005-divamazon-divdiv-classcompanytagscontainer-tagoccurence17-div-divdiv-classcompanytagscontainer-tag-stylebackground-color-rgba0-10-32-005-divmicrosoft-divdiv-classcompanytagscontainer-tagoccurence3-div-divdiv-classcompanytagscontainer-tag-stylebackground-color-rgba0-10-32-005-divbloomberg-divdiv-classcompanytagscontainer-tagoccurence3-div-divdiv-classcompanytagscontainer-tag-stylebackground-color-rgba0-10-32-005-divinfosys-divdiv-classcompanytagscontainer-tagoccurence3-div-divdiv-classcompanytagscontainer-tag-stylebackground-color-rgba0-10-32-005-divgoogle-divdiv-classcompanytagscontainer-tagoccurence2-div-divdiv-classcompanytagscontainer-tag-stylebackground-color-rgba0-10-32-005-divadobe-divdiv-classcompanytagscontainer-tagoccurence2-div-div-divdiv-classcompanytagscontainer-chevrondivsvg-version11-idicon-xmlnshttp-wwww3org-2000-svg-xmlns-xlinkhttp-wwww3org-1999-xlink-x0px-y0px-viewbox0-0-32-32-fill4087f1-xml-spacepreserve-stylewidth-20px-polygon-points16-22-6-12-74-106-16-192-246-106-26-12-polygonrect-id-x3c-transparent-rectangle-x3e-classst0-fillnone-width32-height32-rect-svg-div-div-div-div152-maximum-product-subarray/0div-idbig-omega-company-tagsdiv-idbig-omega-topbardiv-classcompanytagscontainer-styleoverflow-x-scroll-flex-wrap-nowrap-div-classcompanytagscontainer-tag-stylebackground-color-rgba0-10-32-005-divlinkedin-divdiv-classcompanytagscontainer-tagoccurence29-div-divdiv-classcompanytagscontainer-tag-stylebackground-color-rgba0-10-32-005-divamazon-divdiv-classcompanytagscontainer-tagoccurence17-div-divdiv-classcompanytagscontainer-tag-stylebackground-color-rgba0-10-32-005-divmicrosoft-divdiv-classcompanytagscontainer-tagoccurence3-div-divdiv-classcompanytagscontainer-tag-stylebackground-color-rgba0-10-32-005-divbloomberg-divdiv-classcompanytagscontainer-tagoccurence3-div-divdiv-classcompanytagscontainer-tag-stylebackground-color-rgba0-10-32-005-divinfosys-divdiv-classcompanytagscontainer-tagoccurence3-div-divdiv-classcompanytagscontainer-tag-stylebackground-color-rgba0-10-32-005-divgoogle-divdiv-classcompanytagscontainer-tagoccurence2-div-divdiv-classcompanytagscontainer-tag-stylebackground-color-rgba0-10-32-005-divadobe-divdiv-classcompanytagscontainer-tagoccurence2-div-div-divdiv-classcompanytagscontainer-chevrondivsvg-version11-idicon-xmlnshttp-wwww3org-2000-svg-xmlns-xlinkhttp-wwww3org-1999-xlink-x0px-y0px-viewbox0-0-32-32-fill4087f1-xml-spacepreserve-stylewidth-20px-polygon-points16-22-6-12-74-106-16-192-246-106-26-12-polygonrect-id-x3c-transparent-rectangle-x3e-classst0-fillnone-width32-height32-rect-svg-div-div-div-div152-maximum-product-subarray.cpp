class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double mx=INT_MIN;
        int n=nums.size();
        double pref=1,suff=1;
        for(int i=0;i<n;i++){
            if(pref==0)pref=1;
            if(suff==0)suff=1;

            pref*=nums[i];
            suff*=nums[n-i-1];
            mx=max(mx,pref);
            mx=max(mx,suff);
        }
        return (int)mx;
    }
};