class Solution {
public:
    
    void findne(vector<int>& arr,vector<int>& nse,vector<int>& nge){
        int n=arr.size();
        stack<int> st1,st2;
        
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()]>=arr[i]) st1.pop();
            if(st1.empty()) nse[i]=n;
            else nse[i]=st1.top();
            st1.push(i);
            
            while(!st2.empty() && arr[st2.top()]<=arr[i]) st2.pop();
            if(st2.empty()) nge[i]=n;
            else nge[i]=st2.top();
            st2.push(i);
        }
        
    }
    void findpe(vector<int>& arr,vector<int>& pse,vector<int>& pge){
        int n=arr.size();
        stack<int> st1,st2;
        
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[st1.top()]>arr[i]) st1.pop();
            if(st1.empty()) pse[i]=-1;
            else pse[i]=st1.top();
            st1.push(i);
            
            while(!st2.empty() && arr[st2.top()]<arr[i]) st2.pop();
            if(st2.empty()) pge[i]=-1;
            else pge[i]=st2.top();
            st2.push(i);
        }
        
    }
    
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> nse(n),pse(n),nge(n),pge(n);
        findpe(nums,pse,pge);
        findne(nums,nse,nge);
        
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