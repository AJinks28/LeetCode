class Solution {
public:
    
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
    
    vector<int> findnge(vector<int>& arr){
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int> nge(n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<=arr[i]) st.pop();
            if(st.empty()) nge[i]=n;
            else nge[i]=st.top().second;
            st.push({arr[i],i});
        }
        
        return nge;
    }
    vector<int> findpge(vector<int>& arr){
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int> pge(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<arr[i]) st.pop();
            if(st.empty()) pge[i]=-1;
            else pge[i]=st.top().second;
            st.push({arr[i],i});
        }
        
        return pge;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> nse=findnse(nums);
        vector<int> pse=findpse(nums);
        vector<int> nge=findnge(nums);
        vector<int> pge=findpge(nums);
        
        long long sum=0;
        for(int i=0;i<n;i++){
            int l1=nse[i]-i;
            int r1=i-pse[i];
            int l2=nge[i]-i;
            int r2=i-pge[i];
            
            sum-=(l1*r1)*(1ll)*nums[i];
            sum+=(l2*r2)*(1ll)*nums[i];
            
        }
        return sum;
    }
};