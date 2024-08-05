class Solution {
public:
    
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    
    bool compare(string &s,string &t){
        if(s.size() != t.size()+1) return false;
        int i = 0;
        int j = 0;
        while(i < s.size()){
            if(s[i] == t[j] && j < t.size()){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i == s.size() && j == t.size()) return true;
        else return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int mx=-1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};