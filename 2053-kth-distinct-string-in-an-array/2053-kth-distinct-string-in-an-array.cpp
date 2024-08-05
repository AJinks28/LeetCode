class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(string& str: arr){
            if(mp[str]==1) k--;
            if(k==0) return str;
        }
        return "";
    }
};