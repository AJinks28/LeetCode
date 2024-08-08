class Solution {
public:
    int M=1e9+7;
    
    vector<int> findnse(vector<int>& arr){
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int> nse(n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=arr[i]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top().second;
            st.push({arr[i],i});
        }
        
        return nse;
    }
    vector<int> findpse(vector<int>& arr){
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int> pse(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>arr[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top().second;
            st.push({arr[i],i});
        }
        
        return pse;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
        
        vector<int> nse=findnse(arr);
        vector<int> pse=findpse(arr);
        
        for(int i=0;i<n;i++){
            sum+=((nse[i]-i)*(i-pse[i])*(1ll)*arr[i]);
            sum%=M;
        }
        
        return (int)sum%M;
    }
};