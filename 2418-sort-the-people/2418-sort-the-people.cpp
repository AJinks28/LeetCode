class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        
        map<int ,string> mp;
        
        for(int i=0;i<names.size();i++) mp[h[i]]=names[i];
        vector<string> ans;
        
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
            
        return ans;
    }
};