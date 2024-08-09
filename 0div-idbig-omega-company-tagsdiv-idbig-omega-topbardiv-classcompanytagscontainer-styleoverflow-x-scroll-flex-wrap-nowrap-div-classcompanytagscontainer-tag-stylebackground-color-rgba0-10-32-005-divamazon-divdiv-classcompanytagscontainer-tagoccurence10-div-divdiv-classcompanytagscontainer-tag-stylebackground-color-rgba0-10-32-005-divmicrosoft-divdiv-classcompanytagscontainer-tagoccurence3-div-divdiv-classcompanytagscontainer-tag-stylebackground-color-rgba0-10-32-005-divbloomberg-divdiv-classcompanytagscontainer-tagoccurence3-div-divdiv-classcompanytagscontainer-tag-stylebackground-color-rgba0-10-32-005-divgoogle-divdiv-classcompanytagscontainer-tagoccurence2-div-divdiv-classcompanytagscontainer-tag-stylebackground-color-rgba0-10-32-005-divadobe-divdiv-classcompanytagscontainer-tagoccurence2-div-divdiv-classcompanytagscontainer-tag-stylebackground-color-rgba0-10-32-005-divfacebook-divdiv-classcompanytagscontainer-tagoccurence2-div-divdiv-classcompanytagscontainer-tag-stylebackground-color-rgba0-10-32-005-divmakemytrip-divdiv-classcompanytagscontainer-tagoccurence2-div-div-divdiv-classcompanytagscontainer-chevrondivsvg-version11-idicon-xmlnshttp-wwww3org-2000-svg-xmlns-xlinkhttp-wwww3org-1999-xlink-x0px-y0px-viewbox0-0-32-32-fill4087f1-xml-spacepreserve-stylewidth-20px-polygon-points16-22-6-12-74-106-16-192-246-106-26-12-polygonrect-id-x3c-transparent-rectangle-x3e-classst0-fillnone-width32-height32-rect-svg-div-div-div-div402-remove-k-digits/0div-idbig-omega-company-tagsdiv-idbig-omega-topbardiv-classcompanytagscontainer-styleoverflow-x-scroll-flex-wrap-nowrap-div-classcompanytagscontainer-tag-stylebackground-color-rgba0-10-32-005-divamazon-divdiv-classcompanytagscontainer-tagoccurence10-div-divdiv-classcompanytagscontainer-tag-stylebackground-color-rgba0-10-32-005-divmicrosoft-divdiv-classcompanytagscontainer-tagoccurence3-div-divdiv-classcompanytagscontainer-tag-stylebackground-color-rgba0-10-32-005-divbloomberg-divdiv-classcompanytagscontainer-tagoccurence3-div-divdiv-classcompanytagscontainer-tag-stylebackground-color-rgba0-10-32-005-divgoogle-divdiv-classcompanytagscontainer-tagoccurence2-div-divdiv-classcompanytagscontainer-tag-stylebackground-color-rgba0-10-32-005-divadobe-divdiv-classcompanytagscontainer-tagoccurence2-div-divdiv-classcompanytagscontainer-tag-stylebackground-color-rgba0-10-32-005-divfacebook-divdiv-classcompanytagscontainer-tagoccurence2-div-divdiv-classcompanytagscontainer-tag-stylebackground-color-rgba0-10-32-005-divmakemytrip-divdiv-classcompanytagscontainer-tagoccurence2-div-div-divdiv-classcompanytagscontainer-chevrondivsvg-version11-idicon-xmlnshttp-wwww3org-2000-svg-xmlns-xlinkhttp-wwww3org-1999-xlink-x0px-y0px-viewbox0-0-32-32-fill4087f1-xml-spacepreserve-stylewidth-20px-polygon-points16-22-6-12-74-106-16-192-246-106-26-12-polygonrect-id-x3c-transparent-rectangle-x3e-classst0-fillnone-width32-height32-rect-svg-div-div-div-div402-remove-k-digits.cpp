class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans=""; //behave as a Moonotonr stack
        
        for(int i=0;i<num.size();i++){
            
            while(ans.size() && ans.back()>num[i] && k){
                ans.pop_back();
                k--;
            }
            // if(ans.size()==0 && num[i]=='0') continue;
            ans.push_back(num[i]);
        }
        
        while(ans.size() && k){
            ans.pop_back();
            k--;
        }
        int i=0;
        while(ans.size() && ans[i]=='0' )   i++;
        ans=ans.substr(i,ans.size());
        return ans=="" ? "0" : ans;
    }
};