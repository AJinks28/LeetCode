class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i=0,n=nums.size();
        long long ans=0;
        multiset<int> st;
        
        for(int j=0;j<n;j++){
            st.insert(nums[j]);
            
            while(st.size()>1 && *st.rbegin()-*st.begin()>2){
                st.erase(st.find(nums[i]));
                i++;
            }
            ans+=j-i+1;
            
        }
        return ans;
    }
};