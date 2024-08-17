class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        map<int,string> freq;
        for(char &c:s) mp[c]++;
        for(auto it:mp){
            freq[it.second]+=it.first;
        }
        string ans;
        for(auto it:freq){
            int sz=it.first;
            string str=it.second;
            for(char &c:str){
                int n=sz;
                while(n--) ans+=c;
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};