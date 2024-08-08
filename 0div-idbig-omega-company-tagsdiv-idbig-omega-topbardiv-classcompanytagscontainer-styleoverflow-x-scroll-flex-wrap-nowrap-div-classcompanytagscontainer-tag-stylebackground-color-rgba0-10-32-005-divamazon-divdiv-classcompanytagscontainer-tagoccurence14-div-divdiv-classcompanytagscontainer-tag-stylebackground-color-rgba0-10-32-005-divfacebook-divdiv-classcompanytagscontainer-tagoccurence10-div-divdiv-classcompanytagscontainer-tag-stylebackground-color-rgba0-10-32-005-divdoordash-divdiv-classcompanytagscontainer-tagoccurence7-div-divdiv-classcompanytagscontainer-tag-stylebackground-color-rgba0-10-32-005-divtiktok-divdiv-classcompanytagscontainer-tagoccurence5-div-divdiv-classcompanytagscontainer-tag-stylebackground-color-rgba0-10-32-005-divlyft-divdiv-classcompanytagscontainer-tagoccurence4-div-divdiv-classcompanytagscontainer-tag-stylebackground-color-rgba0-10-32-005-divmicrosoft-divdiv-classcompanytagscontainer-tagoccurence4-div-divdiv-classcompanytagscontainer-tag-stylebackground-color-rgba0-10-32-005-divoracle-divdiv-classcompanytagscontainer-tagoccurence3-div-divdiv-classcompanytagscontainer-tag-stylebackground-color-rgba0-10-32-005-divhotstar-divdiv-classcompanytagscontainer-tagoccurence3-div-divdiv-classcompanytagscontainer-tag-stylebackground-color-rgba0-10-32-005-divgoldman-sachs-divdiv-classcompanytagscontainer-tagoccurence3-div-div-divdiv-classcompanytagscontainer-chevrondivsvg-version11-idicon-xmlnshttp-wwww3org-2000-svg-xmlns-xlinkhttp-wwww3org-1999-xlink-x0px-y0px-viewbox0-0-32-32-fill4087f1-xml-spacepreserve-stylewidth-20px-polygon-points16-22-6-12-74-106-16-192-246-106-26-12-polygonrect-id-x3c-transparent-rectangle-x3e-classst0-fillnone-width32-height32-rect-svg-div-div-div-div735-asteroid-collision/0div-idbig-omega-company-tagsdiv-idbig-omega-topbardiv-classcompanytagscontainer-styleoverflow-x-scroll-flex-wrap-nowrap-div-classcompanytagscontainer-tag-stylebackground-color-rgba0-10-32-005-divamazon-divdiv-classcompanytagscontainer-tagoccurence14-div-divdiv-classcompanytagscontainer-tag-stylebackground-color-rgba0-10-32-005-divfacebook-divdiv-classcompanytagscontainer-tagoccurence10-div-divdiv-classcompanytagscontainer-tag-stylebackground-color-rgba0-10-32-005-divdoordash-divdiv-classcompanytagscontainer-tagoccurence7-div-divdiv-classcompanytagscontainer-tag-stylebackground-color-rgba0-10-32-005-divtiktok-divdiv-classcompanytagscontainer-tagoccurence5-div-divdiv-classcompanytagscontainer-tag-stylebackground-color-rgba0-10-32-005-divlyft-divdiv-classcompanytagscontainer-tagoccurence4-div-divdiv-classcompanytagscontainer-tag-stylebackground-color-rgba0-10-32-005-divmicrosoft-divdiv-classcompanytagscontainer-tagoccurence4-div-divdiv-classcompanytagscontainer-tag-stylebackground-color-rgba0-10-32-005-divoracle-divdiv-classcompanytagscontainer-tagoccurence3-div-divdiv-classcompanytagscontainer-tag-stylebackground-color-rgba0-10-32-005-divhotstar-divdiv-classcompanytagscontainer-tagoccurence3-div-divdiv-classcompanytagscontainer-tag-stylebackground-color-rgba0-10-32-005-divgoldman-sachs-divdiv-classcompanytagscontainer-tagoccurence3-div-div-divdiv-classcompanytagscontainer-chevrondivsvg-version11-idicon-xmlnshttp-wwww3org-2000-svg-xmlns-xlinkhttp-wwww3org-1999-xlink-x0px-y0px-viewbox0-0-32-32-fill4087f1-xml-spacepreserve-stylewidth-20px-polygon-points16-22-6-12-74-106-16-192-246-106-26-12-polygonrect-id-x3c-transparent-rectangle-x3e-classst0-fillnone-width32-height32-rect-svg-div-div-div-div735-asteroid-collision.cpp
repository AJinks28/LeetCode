class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(a[i]>0) st.push(a[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(a[i]))
                    st.pop();
                if(!st.empty() && st.top()==abs(a[i])) {
                    st.pop();
                }
                else if(st.empty() || st.top()<0) st.push(a[i]);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) { ans.push_back(st.top()); st.pop(); }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};