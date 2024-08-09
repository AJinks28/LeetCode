class Solution {
public:
    
    vector<int> findnse(vector<int>& a){
        int n=a.size();
        vector<int> nse(n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        
        return nse;
    }
    vector<int> findpse(vector<int>& a){
        int n=a.size();
        vector<int> pse(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        
        return pse;
    }
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        
        vector<int> nse=findnse(h);
        vector<int> pse=findpse(h);
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(nse[i]-pse[i]-1)*h[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        vector<int> h(n,0);
        int i=0;
        while(i<m){
            
            for(int j=0;j<n;j++){
                if(mat[i][j]=='0') h[j]=0;
                else h[j]+=1;
            }
            ans=max(ans,largestRectangleArea(h));
            i++;
        }
        return ans;
    }
};