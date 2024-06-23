class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int> st;
        
        int i=0,mxlen=0;
        for(int j=0;j<n;j++){
            st.insert(nums[j]);
            
            while(*st.rbegin()-*st.begin()>limit){
                st.erase(st.find(nums[i]));
                i++;
            }
            mxlen=max(mxlen,j-i+1);
        }
        return mxlen;
    }
};