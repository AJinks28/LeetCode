class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        
        map<int,int> mp;
        
        int n1=arr1.size(),n2=arr2.size();
        for(int i=0;i<n2;i++){
            for(int j=0;j<n1;j++){
                if(arr1[j]==arr2[i]){
                    ans.push_back(arr1[j]);
                    arr1[j]=-1;
                }
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<n1;i++){
            if(arr1[i]!=-1) ans.push_back(arr1[i]);
        }
        
        return ans;
    }
};