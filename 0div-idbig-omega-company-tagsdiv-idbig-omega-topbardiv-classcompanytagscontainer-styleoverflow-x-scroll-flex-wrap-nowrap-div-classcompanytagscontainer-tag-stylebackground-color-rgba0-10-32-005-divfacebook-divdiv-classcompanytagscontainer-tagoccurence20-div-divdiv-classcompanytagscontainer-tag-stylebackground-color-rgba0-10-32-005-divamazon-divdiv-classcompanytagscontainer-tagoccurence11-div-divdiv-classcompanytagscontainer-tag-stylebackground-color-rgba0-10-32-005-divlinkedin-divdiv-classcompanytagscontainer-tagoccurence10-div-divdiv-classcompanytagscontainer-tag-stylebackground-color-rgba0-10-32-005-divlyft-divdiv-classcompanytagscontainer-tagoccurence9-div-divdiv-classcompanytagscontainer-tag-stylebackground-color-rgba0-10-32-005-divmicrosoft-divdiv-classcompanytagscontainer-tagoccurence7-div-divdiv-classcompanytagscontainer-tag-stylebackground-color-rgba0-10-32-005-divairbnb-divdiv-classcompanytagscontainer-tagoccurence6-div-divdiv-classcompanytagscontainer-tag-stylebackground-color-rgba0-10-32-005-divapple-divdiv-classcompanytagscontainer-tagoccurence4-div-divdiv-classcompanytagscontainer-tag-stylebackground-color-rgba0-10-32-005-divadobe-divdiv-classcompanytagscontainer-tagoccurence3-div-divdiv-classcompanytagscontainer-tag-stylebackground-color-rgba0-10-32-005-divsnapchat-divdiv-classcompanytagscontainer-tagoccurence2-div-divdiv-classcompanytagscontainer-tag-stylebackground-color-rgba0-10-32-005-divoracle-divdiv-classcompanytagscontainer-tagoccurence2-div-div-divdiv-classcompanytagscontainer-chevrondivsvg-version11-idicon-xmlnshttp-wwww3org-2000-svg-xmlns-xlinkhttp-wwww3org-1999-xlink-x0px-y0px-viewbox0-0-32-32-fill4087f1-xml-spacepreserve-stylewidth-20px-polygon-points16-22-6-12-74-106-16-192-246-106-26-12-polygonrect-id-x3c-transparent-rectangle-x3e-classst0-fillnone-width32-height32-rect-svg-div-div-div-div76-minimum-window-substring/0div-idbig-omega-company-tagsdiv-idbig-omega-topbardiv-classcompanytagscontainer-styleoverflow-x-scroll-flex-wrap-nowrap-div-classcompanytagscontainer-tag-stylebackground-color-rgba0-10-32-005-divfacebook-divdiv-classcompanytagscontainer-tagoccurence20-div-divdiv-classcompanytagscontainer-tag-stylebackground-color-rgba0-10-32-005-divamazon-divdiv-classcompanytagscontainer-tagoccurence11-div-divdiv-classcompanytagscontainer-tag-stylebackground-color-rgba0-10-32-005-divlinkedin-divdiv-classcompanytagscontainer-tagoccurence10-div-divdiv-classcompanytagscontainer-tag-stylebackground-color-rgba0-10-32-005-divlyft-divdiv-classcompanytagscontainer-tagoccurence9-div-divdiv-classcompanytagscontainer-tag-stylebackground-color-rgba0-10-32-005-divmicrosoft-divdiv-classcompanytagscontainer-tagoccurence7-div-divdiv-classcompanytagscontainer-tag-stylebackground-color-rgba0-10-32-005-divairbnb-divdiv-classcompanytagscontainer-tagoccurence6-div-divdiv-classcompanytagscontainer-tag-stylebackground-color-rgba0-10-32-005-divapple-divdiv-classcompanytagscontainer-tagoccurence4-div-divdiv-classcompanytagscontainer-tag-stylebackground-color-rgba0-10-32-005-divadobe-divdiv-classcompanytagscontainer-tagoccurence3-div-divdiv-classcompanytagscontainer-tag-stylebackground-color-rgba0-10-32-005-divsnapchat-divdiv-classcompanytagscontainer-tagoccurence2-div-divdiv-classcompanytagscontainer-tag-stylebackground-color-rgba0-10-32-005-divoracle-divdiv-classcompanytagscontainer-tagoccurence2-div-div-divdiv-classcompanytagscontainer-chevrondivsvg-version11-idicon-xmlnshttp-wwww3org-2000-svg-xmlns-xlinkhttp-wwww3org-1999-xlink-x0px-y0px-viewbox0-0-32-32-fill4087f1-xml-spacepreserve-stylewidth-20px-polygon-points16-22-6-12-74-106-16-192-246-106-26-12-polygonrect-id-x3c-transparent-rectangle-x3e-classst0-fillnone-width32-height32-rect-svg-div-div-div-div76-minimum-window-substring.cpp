class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size(),n2=t.size();
        
        unordered_map<char,int> mp;
        for(char &c:t) mp[c]++;
        
        int i=0,ans=1e9,cnt=mp.size(),start=0;
        for(int j=0;j<n1;j++){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            } 
            
            while(cnt==0){
                if(cnt==0){
                    // cout<<ans<<" ";
                    if(ans>j-i+1){
                        ans=j-i+1;
                        start=i;
                    }
                    // cout<<s.substr(start,ans)<<" ";
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) cnt++;
                } 
                i++;
            }
            
            
        }
        return ans==1e9 ? "" : s.substr(start,ans);
    }
};